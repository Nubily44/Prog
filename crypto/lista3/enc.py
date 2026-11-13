
from pathlib import Path
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
import hmac


def cbc_mac(file_path, key, tag_path=None):
    file_path = Path(file_path)
    data = file_path.read_bytes()

    if len(key) not in (16, 24, 32):
        raise ValueError("A chave AES deve possuir 16, 24 ou 32 bytes.")

    # Prefixo de tamanho para segurança com mensagens variáveis
    data = len(data).to_bytes(8, "big") + data

    # Padding com zeros até completar blocos de 16 bytes
    data += b"\x00" * (-len(data) % 16)

    cipher = Cipher(algorithms.AES(key), modes.ECB())
    encryptor = cipher.encryptor()

    state = bytes(16)

    # CBC-MAC
    for i in range(0, len(data), 16):
        block = data[i:i + 16]
        block = bytes(a ^ b for a, b in zip(block, state))
        state = encryptor.update(block)

    encryptor.finalize()

    tag = state.hex()

    # Salva a tag separadamente, preservando o Markdown
    if tag_path is None:
        tag_path = Path(str(file_path) + ".mac")

    Path(tag_path).write_text(tag + "\n", encoding="ascii")

    return tag


def verify_cbc_mac(file_path, key, tag_path=None):
    if tag_path is None:
        tag_path = Path(str(file_path) + ".mac")

    try:
        original_tag = Path(tag_path).read_text(
            encoding="ascii"
        ).strip()

        calculated_tag = cbc_mac_value(file_path, key)

        return hmac.compare_digest(
            original_tag,
            calculated_tag
        )

    except (OSError, ValueError):
        return False


def cbc_mac_value(file_path, key):
    file_path = Path(file_path)
    data = file_path.read_bytes()

    if len(key) not in (16, 24, 32):
        raise ValueError("Chave AES inválida.")

    data = len(data).to_bytes(8, "big") + data
    data += b"\x00" * (-len(data) % 16)

    cipher = Cipher(algorithms.AES(key), modes.ECB())
    encryptor = cipher.encryptor()

    state = bytes(16)

    for i in range(0, len(data), 16):
        block = data[i:i + 16]
        block = bytes(a ^ b for a, b in zip(block, state))
        state = encryptor.update(block)

    encryptor.finalize()

    return state.hex()

if __name__ == "__main__":
    
    cbc_mac("lista3/lista3.md", b"1234567890123456")
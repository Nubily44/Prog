from pathlib import Path
from cryptography.hazmat.primitives.ciphers.aead import AESGCM
import os


def encrypt_file(input_path: str, output_path: str, key: bytes) -> None:
    """
    Encrypt a file using AES-256-GCM.

    Args:
        input_path: Path to the file to encrypt.
        output_path: Path where the encrypted file will be saved.
        key: 32-byte AES key.
    """
    if len(key) != 32:
        raise ValueError("AES-256 requires a 32-byte key.")

    input_path = Path(input_path)
    output_path = Path(output_path)

    data = input_path.read_bytes()

    # GCM requires a unique nonce for every encryption with the same key.
    nonce = os.urandom(12)

    aes = AESGCM(key)
    ciphertext = aes.encrypt(nonce, data, None)

    # Store the nonce together with the ciphertext.
    output_path.write_bytes(nonce + ciphertext)


def decrypt_file(input_path: str, output_path: str, key: bytes) -> None:
    """
    Decrypt a file encrypted with AES-256-GCM.

    Args:
        input_path: Path to the encrypted file.
        output_path: Path where the decrypted file will be saved.
        key: 32-byte AES key.
    """
    if len(key) != 32:
        raise ValueError("AES-256 requires a 32-byte key.")

    input_path = Path(input_path)
    output_path = Path(output_path)

    encrypted_data = input_path.read_bytes()

    nonce = encrypted_data[:12]
    ciphertext = encrypted_data[12:]

    aes = AESGCM(key)
    plaintext = aes.decrypt(nonce, ciphertext, None)

    output_path.write_bytes(plaintext)
    

if __name__ == "__main__":
    # Example usage
    key = os.urandom(32)  # Generate a random 32-byte key
    print(f"Generated AES-256 key: {key.hex()}")
    encrypt_file("lista2/lista2.md", "lista2/lista2.enc", key)
    decrypt_file("lista2/lista2.enc", "lista2/lista2_dec.md", key)
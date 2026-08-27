def shift_cipher(text, shift):
    result = ""

    for char in text:
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            result += chr((ord(char) - base + shift) % 26 + base)
        else:
            result += char

    return result


def vigenere_cipher(text, key):
    result = ""
    key = key.lower()
    key_index = 0

    for char in text:
        if char.isalpha():
            shift = ord(key[key_index % len(key)]) - ord('a')

            base = ord('A') if char.isupper() else ord('a')
            result += chr((ord(char) - base + shift) % 26 + base)

            key_index += 1
        else:
            result += char

    return result

def encrypt_markdown_file(
    input_file,
    output_file,
    method="shift",
    shift=3,
    key="SECRET"
):
    with open(input_file, "r", encoding="utf-8") as f:
        content = f.readlines()

    encrypted_lines = []

    inside_code_block = False

    for line in content:

        # Preserve code blocks
        if line.strip().startswith("```"):
            inside_code_block = not inside_code_block
            encrypted_lines.append(line)
            continue

        if inside_code_block:
            encrypted_lines.append(line)
            continue

        # Separate markdown symbols from text
        match = re.match(r"^([#>*\-\s\d.]*)?(.*)", line)

        if match:
            prefix = match.group(1) or ""
            text = match.group(2)

            if method == "shift":
                encrypted_text = shift_cipher(text, shift)

            elif method == "vigenere":
                encrypted_text = vigenere_cipher(text, key)

            else:
                raise ValueError("Invalid method")

            encrypted_lines.append(prefix + encrypted_text)

    with open(output_file, "w", encoding="utf-8") as f:
        f.writelines(encrypted_lines)

if __name__ == "__main__":
    text = "privacidadepublicatranparenciaprivada"
    encrypted_text = shift_cipher(text, 3)
    print("Shift Cipher Encrypted:", encrypted_text)
    
    dict = {
        'A':'Z',
        'B':'E',
        'C':'B',
        'D':'R',
        'E':'A',
        'F':'S',
        'G':'C',
        'H':'D',
        'I':'F',
        'J':'G',
        'K':'H',
        'L':'I',
        'M':'J',
        'N':'K',
        'O':'L',
        'P':'M',
        'Q':'N',
        'R':'O',
        'S':'P',
        'T':'Q',
        'U':'T',
        'V':'U',
        'W':'V',
        'X':'W',
        'Y':'X',
        'Z':'Y'
    }
    encrypted_text2 = ''.join(dict.get(c, c) for c in text.upper())
    print("Substitution Cipher Encrypted:", encrypted_text2.lower())
    
    encrypted_text3 = vigenere_cipher(text, "senha")
    print("Vigenere Cipher Encrypted:", encrypted_text3.lower())
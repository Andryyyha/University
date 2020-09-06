import re

alphabet = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюя1234567890!?,.;:- '
i = 0
alphabet_numbers = dict()
for el in alphabet:
    alphabet_numbers[el] = i
    i += 1
key_file = open('key.txt', 'r')
key = str()
for line in key_file:
    # line = re.sub(r'[A-Za-z]*', '', line).lower()
    for el in line.lower():
        if el not in alphabet:
            continue
        else:
            key += el
i = 0
# match = re.match(r'[A-Za-z]*', key)
# if match.span() != (0, 0):
#     print('Ключ не должен содержать английских букв!')
#     exit(0)
# key_numbers = dict()
# for k in key:
#     key_numbers[k] = alphabet_numbers[k]
alphabet_numbers_revert = dict((v, k) for k, v in alphabet_numbers.items())
k = 0
encrypted_text = str()


def encrypt():
    file = open('text.txt', 'r')
    text = str()
    for line in file:
        text += line.lower()
    # for line in file:
    #     for el in line.lower():
    #         if el not in alphabet:
    #             continue
    #         else:
    #             text += el
    global encrypted_text, i
    i = 0
    for j in range(0, len(text)):
        if i == len(key):
            i = 0
        if text[j] not in alphabet:
            encrypted_text += text[j]
            continue
        # if text[j] == '\n':
        #     encrypted_text += '\n'
        #     continue
        # elif key[i] == '\n':
        #     i += 1
            # continue
        a = alphabet_numbers[text[j]]
        b = alphabet_numbers[key[i]]
        xk = a + b
        encrypted_text += alphabet_numbers_revert[xk % len(alphabet)]
        i += 1
    # print(encrypted_text)
    encrypted = open('encrypted.txt', 'w')
    encrypted.write(encrypted_text)


# encrypt(text)
# print(encrypted_text)


def decrypt(msg):
    file = open('encrypted.txt', 'r')
    for line in file:
        msg += line.lower()
    # for line in file:
    #     for el in line.lower():
    #         if el not in alphabet:
    #             continue
    #         else:
    #             msg += el
    dectypted_text = str()
    global i
    i = 0
    for j in range(0, len(msg)):
        if i == len(key):
            i = 0
        # if msg[j] == '\n':
        #     dectypted_text += '\n'
        #     continue
        # elif key[i] == '\n':
        #     i += 1
            # continue
        if msg[j] not in alphabet:
            dectypted_text += msg[j]
            continue
        yk = alphabet_numbers[msg[j]] - alphabet_numbers[key[i]]
        if yk < 0:
            yk = yk + len(alphabet)
        dectypted_text += alphabet_numbers_revert[yk]
        i += 1
    decrypted = open('decrypted.txt', 'w')
    decrypted.write(dectypted_text)
    # print(dectypted_text)


# decrypt(encrypted_text)


if __name__ == '__main__':
    print('Выберите опцию:')
    print('Зашифровать - 1')
    print('Расшифровать - 2')
    try:
        option = int(input())
        if option > 2:
            print('Ошибка! Введите корректное значение')
        elif option == 1:
            encrypt()
        else:
            decrypt(encrypted_text)
    except ValueError:
        print('Ошибка! Введите корректное значение')
        exit(0)

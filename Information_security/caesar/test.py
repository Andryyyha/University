print(3 % 50)

import re

alphabet = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюя1234567890!?,.;:- '
print(4 % len(alphabet))
i = 1
alphabet_numbers = dict()
for el in alphabet:
    alphabet_numbers[el] = i
    i += 1
key_file = open('key.txt', 'r')
key = str()
for line in key_file:
    line = re.sub(r'[A-Za-z]*', '', line).lower()
    key += line
# match = re.match(r'[A-Za-z]*', key)
# if match.span() != (0, 0):
#     print('Ключ не должен содержать английских букв!')
#     exit(0)
key_numbers = dict()
for k in key:
    key_numbers[k] = alphabet_numbers[k]
file = open('text.txt', 'r')
text = str()
for line in file:
    line = re.sub(r'[A-Za-z]*', '', line)
    text += line.lower()
i = 1
encrypted_text = str()
alphabet_numbers_revert = dict((v, k) for k, v in alphabet_numbers.items())
k = 0


def encrypt():
    global encrypted_text, i
    for j in range(0, len(text)):
        if i == len(key) - 1:
            i = 1
        xk = alphabet_numbers[text[j]] + alphabet_numbers[key[i]]
        encrypted_text += alphabet_numbers_revert[xk % len(alphabet)]
        i += 1


encrypt()
print(encrypted_text)


def decrypt(msg):
    dectypted_text = str()
    global i
    i = 1
    for j in range(0, len(msg)):
        if i == len(key) - 1:
            i = 1
        yk = alphabet_numbers[msg[j]] - alphabet_numbers[key[i]]
        if yk <= 0:
            yk = yk + len(alphabet) - 1
        dectypted_text += alphabet_numbers_revert[yk % len(alphabet)]
        i += 1
    print(dectypted_text)


decrypt(encrypted_text)

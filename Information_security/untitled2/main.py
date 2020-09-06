import re

rus_eng_analog = dict()

rus_eng_analog['а'] = 'a'
rus_eng_analog['А'] = 'A'
rus_eng_analog['В'] = 'B'
rus_eng_analog['е'] = 'e'
rus_eng_analog['Е'] = 'E'
rus_eng_analog['к'] = 'k'
rus_eng_analog['К'] = 'K'
rus_eng_analog['М'] = 'M'
rus_eng_analog['Н'] = 'H'
rus_eng_analog['о'] = 'o'
rus_eng_analog['О'] = 'O'
rus_eng_analog['р'] = 'p'
rus_eng_analog['Р'] = 'P'
rus_eng_analog['с'] = 'c'
rus_eng_analog['С'] = 'C'
rus_eng_analog['Т'] = 'T'
rus_eng_analog['у'] = 'y'
rus_eng_analog['х'] = 'x'
rus_eng_analog['Х'] = 'X'

eng_rus_analog = dict((v, k) for k, v in rus_eng_analog.items())

mask = 0x80
# print(eng_rus_analog)

file = open('text_to_hide.txt', 'r+b').read()
text_block_file = open('text_block.txt', 'r')
text_block = str()
for line in text_block_file:
    text_block += re.sub(r'[A-Za-z]*', '', line)
text_to_hide = bytearray(file)
k = 0


def hide_text():
    j = 0
    msg = str()
    for b in text_to_hide:
        for i in range(8):
            if b & (mask >> i) >= 1:
                while text_block[j] not in rus_eng_analog.keys():
                    msg += text_block[j]
                    j += 1
                msg += rus_eng_analog[text_block[j]]
                j += 1
            else:
                while text_block[j] not in rus_eng_analog.keys():
                    msg += text_block[j]
                    j += 1
                msg += text_block[j]
                j += 1
    if j < len(text_block):
        msg += text_block[j+1:]
    res = open('hidden.txt', 'w')
    res.write(msg)


# hide_text()


def disclosure_text():
    file = open('hidden.txt', encoding='utf-8')
    msg = str()
    result = list()
    for line in file:
        msg += line

    for i in msg:
        if i in rus_eng_analog.keys():
            result += '0'
        if i in eng_rus_analog.keys():
            result += '1'

    result = "".join(result)
    last = str()
    # b_arr = bytearray()
    to_file = str()
    for i in range(0, len(result)):
        cur = result[i*8: (i+1)*8]
        a = int(cur, base=2)
        if last == "00000000" and cur == "00000000":
            break
        to_file += cur
        # b_arr.extend(a.to_bytes(1, 'little'))
        last = cur
    to_file = int(to_file, base=2)
    to_file = to_file.to_bytes((to_file.bit_length() + 7) // 8, 'big').decode(encoding='utf-8', errors='replace')
    print(to_file[:len(to_file) - 1])
    disc = open('disclosured.txt', 'w').write(to_file[:len(to_file) - 1])
    # result_message = b_arr.decode('utf-8', errors='ignore')
    # print(result_message)
    # disc = open('disclosured.txt', 'w').write(result_message[:len(result_message) - 1])


disclosure_text()



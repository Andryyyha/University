import numpy as np


file = open('dpjSWPK23Hg.jpg', 'r+b').read()
b = bytearray(file)

crc_poly = np.ubyte(0xd5)
bit_mask = np.ubyte(0x80)


def crc8(byte, crc):
    for i in range(8):
        first_bit = crc & bit_mask
        crc = crc << np.ubyte(1)
        if np.ubyte(byte & (bit_mask >> i)):
            crc = crc | np.ubyte(1)
        if first_bit:
            crc = crc ^ crc_poly
    return crc


def calc_crc8():
    crc = np.ubyte(0)
    for i in b:
        crc = crc8(i, crc)
    crc = crc8(0b00000000, crc)
    print('Контрольнаяя сумма')
    print(hex(crc))


if __name__ == '__main__':
    calc_crc8()
from math import sqrt

a = [2, 4, 8, 15]
b = [3, 6, 8, 14]
i = 0
j = 0
min_l = min(len(a), len(b))
while i < len(a) & j < len(b):
    for k in range(min_l):
        cur_a = a[k]
        cur_b = b[k]
        if cur_a == cur_b:
            i += 1
            j += 1
        else:
            if cur_a < cur_b:
                i += 1
                i += sqrt(len(a))
            else:
                j += 1

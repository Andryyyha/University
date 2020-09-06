import os

patternLength = 16
res = list()


def walk(dir):
    for name in os.listdir(dir):
        path = os.path.join(dir, name)
        if os.access(path, os.R_OK):
            if os.path.isfile(path):
                file = open(path, 'rb')
                file.seek(offset)
                chunk = file.read(patternLength)
                if chunk == needToFindPattern:
                    res.append(path)
            else:
                walk(path)


print('Введите абсолютный путь до файла')
pathToFile = input()

print('Введите смещение')
offset = int(input())

if os.path.isfile(pathToFile):
    if offset + patternLength > os.path.getsize(pathToFile):
        print("Размер файла меньше смещения!")
        exit()
    fileP = open(pathToFile, 'rb')
    fileP.seek(offset)
    needToFindPattern = fileP.read(patternLength)
else:
    print('Неверный путь до файла!')
    exit()

pathDir = input('Введите абсолютный путь до директории')

if os.path.isdir(pathDir):
    walk(pathDir)
    print('Заданная сигнатура найдена в файлах:')
    print('\n'.join(res))
else:
    print('Неверный путь к директории')
    exit()
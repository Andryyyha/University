import hashlib
import os
import re
import pyAesCrypt


full_path = "/Users/andryyyha/PyCharmProjects/password_system/home/"

my_db = dict()
logged_id = False


def load():
    file = open('users.txt', 'r')
    for line in file:
        user, hpassword = line.split(' ')
        my_db[user] = re.sub(r'\n', '', hpassword)


def encrypt(user, password):
    h = hashlib.sha256()
    h.update(bytes(password, encoding='utf-8'))
    buffer = 64 * 1024
    for root, dirs, files in os.walk(full_path + user):
        files = [f for f in files if not f[0] == '.']
        dirs[:] = [d for d in dirs if not d[0] == '.']
        for file in files:
            pyAesCrypt.encryptFile(root + '/' + file, root + '/' + file + '.aes', h.hexdigest(), buffer)
            os.remove(root + '/' + file)


def decrypt(user, password):
    h = hashlib.sha256()
    h.update(bytes(password, encoding='utf-8'))
    buffer = 65536
    for root, dirs, files in os.walk(full_path + user):
        files = [f for f in files if not f[0] == '.']
        dirs[:] = [d for d in dirs if not d[0] == '.']
        for file in files:
            pyAesCrypt.decryptFile(root + '/' + file, root + '/' + file[:len(file) - 4], h.hexdigest(), buffer)
            os.remove(root + '/' + file)


def register():
    user, password, repeat = str(), str(), str()
    try:
        user = input("Логин: ").strip()
        if user in my_db.keys():
            print("Пользователь с таким именем уже существует!")
            return '', ''
        else:
            if len(user) == 0:
                print("Логин не может быть пустым!")
                return '', ''
            password = input("Пароль: ").strip()
            repeat = input("Повторите пароль: ").strip()
            while repeat != password:
                print("Пароли не совпадают! Поробуйте снова.")
                password = input("Пароль: ").strip()
                repeat = input("Повторите пароль: ").strip()
            if len(password) < 3 or len(password) > 10:
                print("Пароль должен содержать от 3 до 10 символов!")
                return '', ''
            h = hashlib.sha256()
            h.update(bytes(password, encoding='utf-8'))
            my_db[user] = h.hexdigest()
            write()
            print("Создание домашней папки.")
            try:
                os.mkdir(full_path + user)
            except FileExistsError:
                os.rmdir(full_path + user)
            print("Регистрация прошла успешно.")
    except KeyboardInterrupt:
        write()
    return user, password


def login():
    user, password = str(), str()
    try:
        global logged_id
        user = input("Логин: ").strip()
        password = input("Пароль: ").strip()
        h = hashlib.sha256()
        h.update(bytes(password, encoding='utf-8'))
        if user not in my_db.keys() or my_db[user] != h.hexdigest():
            print("Неверный логин и/или пароль!")
        else:
            logged_id = True
            decrypt(user, password)
            print("Файлы расшифрованы. Добро пожаловать!")
    except KeyboardInterrupt:
        write()
    return user, password


def logout(user, password):
    try:
        global logged_id
        logged_id = False
        encrypt(user, password)
        print("Данные зашифрованы.")
        print("Вы вышли из системы.")
    except KeyboardInterrupt:
        write()


def write():
    file = open('users.txt', 'w')
    for k, v in my_db.items():
        file.write(k + " " + v + '\n')


def man():
    print("Парольная система.",
           "Команды:",
           "? - список команд",
           "register - регистрация",
           "login - вход в систему",
           "logout - выход из системы",
           "exit - заверешение программы", sep='\n')


def pswd():
    try:
        load()
        # user = str()
        # password = str()
        global logged_id, user, password
        logged_id = False
        console_output = ">"
        man()
        while True:
            cmd = input(console_output)
            if cmd == '?':
                man()
            # elif cmd in ['register', 'login']:
            #     if logged_id:
            #         print("Пользователь уже в системе")
            #         continue
                # user = input("Логин: ").strip()
                # password = input("Пароль: ").strip()
            elif cmd == 'login':
                if logged_id:
                    print("Пользователь уже в системе")
                    continue
                user, password = login()
                if logged_id:
                    console_output = user + '>'
            elif cmd == 'register':
                if logged_id:
                    print("Пользователь уже в системе")
                    continue
                user, password = register()
            elif cmd == 'logout':
                logout(user, password)
                console_output = '>'
            elif cmd == 'exit':
                if logged_id:
                    logout(user, password)
                write()
                break
            else:
                print("Неверная команда! Чтобы посмотреть список команд введите '?'")
    except KeyboardInterrupt:
        if logged_id:
            logout(user, password)
        write()
    exit(0)


if __name__ == '__main__':
    pswd()
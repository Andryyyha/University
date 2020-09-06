import tkinter.filedialog as fd
from tkinter import Tk
import bitstring
import re

PATTERN = "[^\w\d\n.?!,:\-\)\(\]\[ ]"

def give_filename(title):
    filename = fd.askopenfilename(defaultextension='.txt',
                                  filetypes=[("Text file", "*.txt")],
                                  title=title)
    return filename

def open_file(title):
    filename = give_filename(title)
    file_data = None
    if filename != "":
        try:
            with open(filename, 'rb') as f:
                file_data = bitstring.Bits(f.read())
        except IOError:
            print("Incorrect file")
    else:
        print("Choose {} file".format(title))
    return file_data


def rows_count(container_file_name, block_size=1024, encoding="cp1251"):
    try:
        with open(container_file_name, "r") as file:
            return sum(block.count('\n') for block in iter(lambda: file.read(block_size), ''))
    except:
        return 0


def encode(file_data, container_file_name, result_file, encoding="cp1251"):
    try:
        # file_data = file_data[::-1]
        with open(container_file_name, "r", encoding=encoding) as container, \
                open(result_file, "w") as result:
            for row, bit in zip(container, file_data):
                row = row.strip()
                if bit:
                    result.write("{} \n".format(row))
                else:
                    result.write("{}\n".format(row))
            # for row in container:
            #    result.write("{}\n".format(row.strip()))
    except:
        print("Encoding error!")


def decode(cryptogramm, result_file, encoding="cp1251"):
    result_message = []
    with open(cryptogramm, "r", encoding=encoding) as container, \
            open(result_file, "w", encoding=encoding) as result:
        for row in container:
            row = row.strip('\n')
            if row and row[-1] == " ":
                result_message.append('1')
            else:
                result_message.append('0')

        result_message = "".join(result_message)
        result_message = int(result_message, 2)
        result_message = result_message.to_bytes((result_message.bit_length() + 7) // 8, 'big').decode(encoding=encoding, errors='replace')
        print(result_message)
        result.write(result_message)



def get_save_filename(title):
    filename = fd.asksaveasfilename(defaultextension=".txt",
                                    filetypes=[("Text file", "*.txt")],
                                    title=title)
    if filename == "": print("Choose {} file".format(title))
    return filename


def print_menu():
    print("\nhide - hide information in container text\n"
          "extract - extract information from container text\n"
          "i - show information\n"
          "exit - close program\n")


def main_fun():
    global ENCODING
    root = Tk()
    root.attributes('-topmost', True)
    root.wm_withdraw()
    print_menu()
    while True:
        command = input(">>: ").lower().strip()
        if command == "hide":
            file_data = open_file("Open text")
            if file_data is None: continue
            container_file = give_filename("Container file")
            if container_file == "": continue
            if len(file_data) > rows_count(container_file):
                print("Сontainer is too small!")
                continue
            result_file = get_save_filename("Cryptogramm")
            if result_file == "": continue
            encode(file_data, container_file, result_file)
        elif command == "extract":
            result_file = give_filename("Cryptogramm")
            if result_file == "": continue
            decrypted_file = get_save_filename("Decrypted file")
            if decrypted_file == "": continue
            decode(result_file, decrypted_file)
        elif command == "i":
            print_menu()
        elif command == "exit":
            break
        else:
            print("Unknown command")
    root.destroy()

if __name__ == "__main__":
    main_fun()

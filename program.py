def __mikroc_main():
    print(f"\n              ASCII tabulka\n\n    ", end="")
    i = 0
    while (i < 16):
        print(f" %X" % (i), end="")
        i += 1
    print(f"\n   ", end="")
    i = 0
    while (i < 35):
        print(f"-", end="")
        i += 1
    i = 32
    while (i < 128):
        print(f"\n %X|" % (i), end="")
        j = i
        while (j < (i + 16)):
            if (j < 127):
                print(f" %c" % (j), end="")
            else:
                print(f"  ", end="")
            j += 1
        print(f" |", end="")
        i += 16
    print(f"\n   ", end="")
    i = 0
    while (i < 35):
        print(f"-", end="")
        i += 1
    print(f"\n\n", end="")
    pass

if __name__ == '__main__':
    __mikroc_main()
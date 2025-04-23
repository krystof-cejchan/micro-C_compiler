def __mikroc_main():
    print(f"Zadej 2 prirozena cisla: ", end="")
    a = int(input())
    b = int(input())
    if ((a < 1) or (b < 1)):
        print(f"\n\nChybna cisla", end="")
    else:
        while True:
            zbytek = (a % b)
            a = b
            b = zbytek
            if not (zbytek != 0): break
        print(f"\nNejvetsi spolecny delitel: %i" % (a), end="")
    print(f"\n\n", end="")

if __name__ == '__main__':
    __mikroc_main()
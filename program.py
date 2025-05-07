def __mikroc_main():
    print(f"Zadej cislo: ", end="")
    a = int(input())
    p = 0
    b = 1
    while True:
        if (a & b):
            p ^= 1
        b = ((b << 1) & 0xFFFFFFFF)
        if not b: break
    if (p == 0):
        print(f"\n  suda parita \n\n", end="")
    else:
        print(f"\n  licha parita\n\n", end="")
    pass

if __name__ == '__main__':
    __mikroc_main()
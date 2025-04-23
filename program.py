def __mikroc_main():
    print(f"\n", end="")
    b = 0
    a = 1
    print(f"%10i" % (b), end="")
    print(f"%10i" % (a), end="")
    n = 2
    while True:
        c = (a + b)
        b = a
        a = c
        if ((n % 10) == 0):
            print(f"\n", end="")
        print(f"%10i" % (a), end="")
        n += 1
        if not (n < 40): break
    print(f"\n\n", end="")

if __name__ == '__main__':
    __mikroc_main()
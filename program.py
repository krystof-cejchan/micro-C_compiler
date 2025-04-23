def __mikroc_main():
    print(f"Zadej cislo vetsi nez 1: ", end="")
    a = int(input())
    if (a < 2):
        print(f"\nChybne cislo", end="")
    else:
        print(f"\n", end="")
        r = 0
        m = r
        n = 0
        while ((a % 2) == 0):
            n += 1
            a //= 2
        if n:
            print(f" 2", end="")
            if (n > 1):
                print(f"^%u" % (n), end="")
                r = 1
            m = 1
        i = 3
        while (a > 1):
            n = 0
            while ((a % i) == 0):
                n += 1
                a //= i
            if n:
                if m:
                    print(f" *", end="")
                print(f" %u" % (i), end="")
                if (n > 1):
                    print(f"^%u" % (n), end="")
                    r = 1
                m = 1
            i += 2
        if r:
            print(f"   .. ^ oznacuje mocninu", end="")
    print(f"\n\n", end="")

if __name__ == '__main__':
    __mikroc_main()
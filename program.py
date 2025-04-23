def __mikroc_main():
    
    print(f"\n    Prvocisla do 1000\n\n", end="")
    cislo = 2
    print(f"%5i" % (cislo), end="")
    pocet = 1
    cislo += 1
    while True:
        
        prvocislo = 1
        delitel = 3
        while ((delitel * delitel) <= cislo):
            
            if ((cislo % delitel) == 0):
                
                prvocislo = 0
                break
            delitel += 2
        if prvocislo:
            
            print(f"%5i" % (cislo), end="")
            if ((pocet % 10) == 0):
                print(f"\n", end="")
        cislo += 2
        if not (cislo <= 1000): break
    print(f"\n\n", end="")

if __name__=='__main__':
    __mikroc_main()
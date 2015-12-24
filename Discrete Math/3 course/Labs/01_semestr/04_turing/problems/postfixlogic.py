__author__ = "Dmitry Philippov"

import sys

sys.stdout = open("postfixlogic.out", "w")


def main():
    print("""1
S 0 -> now 0 >
S 1 -> now 1 >
now _ -> fillblank _ <
fillblank * -> fillblank _ <
fillblank 0 -> AC 0 ^
fillblank 1 -> AC 1 ^
now 0 -> zeroleft * <
zeroleft _ -> setzero _ >
zeroleft * -> zeroleft * <
zeroleft _ -> now _ ^
zeroleft 0 -> setzero 0 >
zeroleft 1 -> setzero 1 >
setzero * -> zeroright 0 >
zeroright * -> zeroright * >
zeroright _ -> now _ ^
zeroright 0 -> now 0 ^
zeroright 1 -> now 1 ^
zeroright o -> now o ^
zeroright a -> now a ^
now 1 -> oneleft * <
oneleft _ -> setone _ >
oneleft * -> oneleft * <
oneleft 0 -> setone 0 >
oneleft 1 -> setone 1 >
setone * -> oneright 1 >
oneright * -> oneright * >
oneright 0 -> now 0 ^
oneright 1 -> now 1 ^
oneright o -> now o ^
oneright a -> now a ^
now a -> andleft * <
andleft * -> andleft * <
andleft 0 -> andleftzero * <
andleftzero 0 -> andright 0 >
andleftzero 1 -> andright 0 >
andright * -> andright * >
andright _ -> now _ ^
andright 0 -> now 0 ^
andright 1 -> now 1 ^
andright o -> now o ^
andright a -> now a ^
andleft 1 -> andleftone * <
andleftone 0 -> andright 0 >
andleftone 1 -> andright 1 >
now o -> orleft * <
orleft * -> orleft * <
orleft 0 -> orleftzero * <
orleftzero 0 -> orright 0 >
orleftzero 1 -> orright 1 >
orright * -> orright * >
orright _ -> now _ ^
orright 0 -> now 0 ^
orright 1 -> now 1 ^
orright o -> now o ^
orright a -> now a ^
orleft 1 -> orleftone * <
orleftone 0 -> orright 1 >
orleftone 1 -> orright 1 >""")

if __name__ == "__main__":
    main()

__author__ = "Dmitry Philippov"

import sys

sys.stdout = open("mirror.out", "w")


def main():
    print("""start: s
accept: ac
reject: rj
blank: _
s 0 -> findlast 0 ^
s 1 -> findlast 1 ^
findlast 0 -> findlast 0 >
findlast 1 -> findlast 1 >
findlast _ -> onlast _ <
findlast . -> onlast . <
findlast * -> onlast * <
onlast 0 -> findblankzero . >
onlast 1 -> findblankone * >
findblankzero . -> findblankzero . >
findblankzero * -> findblankzero * >
findblankzero 0 -> findblankzero 0 >
findblankzero 1 -> findblankzero 1 >
findblankzero _ -> gotostart 0 <
findblankone . -> findblankone . >
findblankone * -> findblankone * >
findblankone 0 -> findblankone 0 >
findblankone 1 -> findblankone 1 >
findblankone _ -> gotostart 1 <
gotostart . -> gotostart . <
gotostart * -> gotostart * <
gotostart 0 -> gotostart 0 <
gotostart 1 -> gotostart 1 <
gotostart _ -> onestepright _ >
onestepright . -> restorestring . ^
onestepright * -> restorestring * ^
onestepright 0 -> findlast 0 ^
onestepright 1 -> findlast 1 ^
restorestring . -> restorestring 0 >
restorestring * -> restorestring 1 >
restorestring _ -> finally _ <
restorestring 1 -> finally 1 <
restorestring 0 -> finally 0 <
finally 1 -> finally 1 <
finally 0 -> finally 0 <
finally _ -> makeac _ >
makeac 0 -> ac 0 ^
makeac 1 -> ac 1 ^""")

if __name__ == "__main__":
    main()

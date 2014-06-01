__author__ = "Dmitry Philippov"

import sys

inputFile = ""
outputFile = ""

if inputFile == "":
    reader = sys.stdin
    writer = sys.stdout
else:
    reader = open(inputFile + ".in", "r")
    writer = open(outputFile + ".out", "w")

''' Solution '''

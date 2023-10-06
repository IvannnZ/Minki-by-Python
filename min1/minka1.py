from math import fabs


def My_Len(a):
    a = int(fabs(a))
    c = 1
    while (a > 0):
        c += 1
        a = a // 2
    return c


def better_bin(num_get):
    c = 0
    for i in range(My_Len(num_get)):
        c += num_get & 1
        num_get = num_get >> 1
    return c


try:
    while True:
        num = int(input("Enter Number:"))
        print(better_bin(num))
except:
    print("ERROR")

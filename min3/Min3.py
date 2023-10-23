def func(a):
    return [b.split() for b in a.split("|")]


print(func("1 2 3 | 4 5 6 | 7 8 9 | 10"))

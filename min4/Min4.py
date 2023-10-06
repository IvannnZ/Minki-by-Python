def rebild_tuple(a):
    b = {}
    for key, value in a.items():
        # print(key, value)
        if value not in b:
            b[value] = key
        else:
            print(b[value], len(b[value]))
            if type(b[value]) == type(str()):
                c = (b[value], key)
            else:
                c = (*b[value], key)
            b[value] = c

    return b


a = {"Ivanov": 97832, "Petrov": 55521, "Kuznecov": 97832, "Ivanov2": 97832}
# -> {97832: ("Ivanov", "Kuznecov"), 55521: "Petrov"}
print(rebild_tuple(a))

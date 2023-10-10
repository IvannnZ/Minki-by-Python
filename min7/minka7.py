def flatten(list_in, limit=0):
    if limit == 1:
        return list_in
    list_ret = []
    for i in list_in:
        if not ((isinstance(i, list))):
            list_ret.append(i)
        elif isinstance(i, list):
            for j in flatten(i, limit - 1):
                list_ret.append(j)
    return list_ret


print(flatten([1, 2, [4, 5], [6, [7]], 8], 1))
print(flatten([1, 2, [4, 5], [6, [7]], 8], 2))
print(flatten([1, 2, [4, 5], [6, [7]], 8], 3))

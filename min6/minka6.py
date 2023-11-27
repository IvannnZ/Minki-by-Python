def flatten(list_in):
    """This funcyion unpack list and list in it
    :param this function учшые too, too, for what i exist
    :parameter list
    """
    list_ret = []
    for i in list_in:
        if not isinstance(i, list):
            list_ret.append(i)
        else:
            for j in flatten(i):
                list_ret.append(j)
    return list_ret


print(flatten([1, 2, [4, 5], [6, [7]], 8]))

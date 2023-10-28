def my_len(list):
    return len(list if type(list) == type(["", ""]) else " ")


def my_max_len(list):
    if type(list) == type(["", ""]):
        return max(len(i) for i in list)
    else:
        return len(list)


def my_max_len_colum(num, list, one_str):
    return max(*(len(str(i[num])) for i in list), len(one_str))


def format_table(benchmarks, algos, result):
    all_len = [0] * (my_len(algos) + 1)
    all_len[0] = my_max_len(benchmarks + ["Benchmarks"])
    c = 0
    for i in algos:
        all_len[c + 1] = my_max_len_colum(c, result, algos[c])
        c += 1

    def print_one_line(Ben, arr):
        answer = f"|{Ben.center(all_len[0] + 2)}|"
        c = 1
        for i in arr:
            answer += f"{str(i).center(all_len[c] + 2)}|"
            c += 1
        print(answer)

    print_one_line("Benchmarks", algos)
    print("|" + "-" * (sum(all_len) + (len(all_len) * 3) - 1) + "|")
    c = 0
    for i in result:
        print_one_line(benchmarks[c], i)
        c += 1
    print()


some = (["best case", "worst case"], ["quick sort", "merge sort", "bubble sort"], [[1.23, 1.56, 2.0], [3.3, 2.9, 3.9]])

format_table(*some)

some = (["best case", "worst case"], ["merge sort", "bubble sort"], [[1.23, 2.0], [2.9, 3.9]])

format_table(*some)

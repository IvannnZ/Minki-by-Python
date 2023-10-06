def my_zip(a, b):
    return [(a[i], b[i]) for i in range(min(len(a), len(b)))]  # я не понял как это сделать не линивым алгоритмом


print(my_zip([1, 2, 3], ["a", "b"]))

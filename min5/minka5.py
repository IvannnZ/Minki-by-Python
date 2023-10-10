def my_specialize(f, *args, **kwargs):
    def func_for_ret(*more_args, **more_kwargs):
        combined_args = args + more_args
        combined_kwargs = {**kwargs, **more_kwargs}
        return f(*combined_args, **combined_kwargs)

    return func_for_ret


def my_sum(x, y):
    return x + y


plus_one = my_specialize(my_sum, y=1)
just_two = my_specialize(my_sum, 1, 1)

print(plus_one(10))  # 11
print(just_two())  # 2

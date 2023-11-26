def coroutine(func):
    def wrapper(*args, **kwargs):
        fun = func(*args, **kwargs)
        next(fun)
        return fun
    return wrapper


@coroutine
def storage():
    values = set()
    was_there = False

    while True:
        val = yield was_there
        was_there = val in values
        if not was_there:
            values.add(val)


st = storage()
print(st.send(42)) # False
print(st.send(42)) # True
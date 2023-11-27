import functools

'''
TODO
убрать копипасту
'''


def deprecated(since=None, will_be_removed=None):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            name = func.__name__
            answer = f"Warning: function {name} is deprecated"
            if since is None:
                answer += ". It will be removed in"
            else:
                answer += f" since version {since}. It will be removed in"

            if will_be_removed is None:
                answer += " future versions."
            else:
                answer+=f" version {will_be_removed}."
            print(answer)

            return func(*args, **kwargs)

        return wrapper

    return decorator


@deprecated(since="1.0", will_be_removed="5.0")
def bar():
    print("Hello from bar")


@deprecated(will_be_removed="3.0")
def baz():
    print("Hello from baz")


bar()
baz()

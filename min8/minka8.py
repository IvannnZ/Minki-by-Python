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

            if since is None and will_be_removed is None:
                print(f"Warning: function {name} is deprecated. It will be removed in future versions.")
            elif since is None:
                print(f"Warning: function {name} is deprecated. It will be removed in version {will_be_removed}.")
            elif will_be_removed is None:
                print(
                    f"Warning: function {name} is deprecated since version {since}. It will be removed in future versions.")
            else:
                print(
                    f"Warning: function {name} is deprecated since version {since}. It will be removed in version {will_be_removed}.")

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

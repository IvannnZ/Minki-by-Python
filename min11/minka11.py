

class Singleton:
    _instances = {}

    def __new__(cls, *args, **kwargs):
        print(cls, *args, **kwargs)
        if cls not in cls._instances:
            cls._instances[cls] = super().__new__(cls)

        return cls._instances[cls]


class Counter():
    """Special class to count things"""


def __init__(self, initial_count=0, step=1):
    self.count = initial_count
    self.step = step


def increment(self):
    self.count += self.step

class Counter2():
    """Special class to count things"""


def __init__(self, initial_count=0, step=1):
    self.count = initial_count
    self.step = step


def increment(self):
    self.count += self.step



class GlobalCounter(Singleton, Counter):
    pass


class GlobalCounter2(Singleton, Counter):
    pass


gc1 = GlobalCounter()
gc2 = GlobalCounter()

print(id(gc1) == id(gc2))



gc12 = GlobalCounter2()
gc22 = GlobalCounter2()
gc23 = GlobalCounter2()


print(id(gc12) == id(gc22), id(gc23) == id(gc22))

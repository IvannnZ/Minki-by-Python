class LRUCache_2: # TODO сделать через отдельно хеш таблицу и лист
    def __init__(self, capacity=16):
        pass

dict()
class LRUCache:
    def __init__(self, capacity=16):
        self.capacity = capacity
        self.box = {}

    def put(self, key, value):
        if key in self.box:
            del self.box[key]
            self.box[key] = value
        else:
            if self.capacity <= len(self.box):
                del self.box[list(self.box.keys())[0]]
            self.box[key] = value
        pass

    def get(self, key):
        if key in self.box:
            value = self.box[key]
            del self.box[key]
            self.box[key] = value
            return value

    def print(self):
        print(self.box, len(self.box))


a = LRUCache()

a.put(10, 1)
a.put(1, 2)
a.put(5, 3)
a.put(2, 4)

a.print()
a.put(110, 1)
a.put(11, 2)
a.put(15, 3)
a.put(12, 4)

a.put(210, 1)
a.put(21, 2)
a.put(25, 3)
a.put(22, 4)

a.put(310, 1)
a.put(31, 2)
a.put(35, 3)
a.put(32, 4)

a.print()

print(f" {a.get(10)}")

a.print()
a.put(410, 1)
a.put(41, 2)
a.put(45, 3)
a.put(42, 4)

a.print()

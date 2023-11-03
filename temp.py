class Temp:
    def __init__(self):
        self.lst = []

    def f(self, item):
        def insert(item):
            return item.price > 0
        if insert(item):
            self.lst.append(item)

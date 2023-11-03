class Temp:
    @staticmethod
    def add(x, y):
        return x + y

    @staticmethod
    def mul(x, y):
        return x * y


result1 = Temp.add(5, 3)
result2 = Temp.mul(4, 6)

print(result1)
print(result2)

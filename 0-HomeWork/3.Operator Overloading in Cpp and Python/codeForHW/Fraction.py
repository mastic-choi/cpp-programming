import math
class Fraction:
    def __init__(self, numerator: int, denominator: int):
        self.__num = numerator
        self.__den = denominator
    def __add__(self, other):
        result = Fraction((self.__num * other.__den )+(other.__num * self.__den), self.__den * other.__den)
        result.reduce()
        return result
    def __sub__(self, other): 
        result = Fraction((self.__num * other.__den )-(other.__num * self.__den), self.__den * other.__den)
        result.reduce()
        return result
    def __mul__(self, other): 
        result = Fraction((self.__num * other.__num ), (self.__den * other.__den))
        result.reduce()
        return result
    def __truediv__(self, other): 
        result = Fraction((self.__num * other.__den), (self.__den * other.__num))
        result.reduce()
        return result
    def __neg__(self): 
        return Fraction(-self.__num, self.__den)
    def __iadd__(self, other): 
        tmp = self + other
        tmp.reduce()
        self.__num = tmp.__num
        self.__den = tmp.__den
        return self
    def __eq__(self, other): 
        return(self.__num*other.__den == self.__den*other.__num)
    def __lt__(self, other):
        return(self.__num_*other.__den) <(other.__num*self.__den)
    def __bool__(self): 
        return(self.__num!= 0)
    def __getitem__(self, index):  # 0: 분자, 1: 분모
        if (index == 0): return self.__num
        elif(index == 1): return self.__den
    def __str__(self): 
        return f"{self.__num}/{self.__den}"
    def __repr__(self): 
        return f"Fraction({self.__num}, {self.__den})"
    def reduce(self):
        common = math.gcd(self.__num, self.__den)
        self.__num //= common
        self.__den //= common
        if self.__den < 0:
            self.__den = -self.__den
            self.__num = -self.__num

a = Fraction(1, 2)
b = Fraction(1, 3)
print(f"{a} + {b} = {a + b}")
print(f"{a} * {b} = {a * b}")
print(f"{a} == {Fraction(2, 4)} : {a == Fraction(2, 4)}")
if a:
    pass
print(f"{a} is nonzero")
a += b
print(f"a += b : {a}")
print(f"분자: {a[0]}, 분모: {a[1]}")
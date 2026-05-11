class A:
    def __init__(self, data = 0):
        self.__data = data #이름 앞 __는 C++의 private 멤버처럼 취급  
    def getter(self):
        print(self.__data)
    def __add__(self, other):
        return A(self.__data + other.__data)
    def __sub__(self, other):
        return A(self.__data - other.__data)
    def __mul__(self, other):
        return A(self.__data * other.__data)
    def __truediv__(self, other):
        if other.__data != 0:
            return A(self.__data / other.__data)
        else:
            return A(0)
    def __mod__(self, other):
        if other.__data != 0:
            return A(self.__data % other.__data)
        else:
            return A(0)
    def __radd__(self, other):
        return A(other + self.__data)

    def __rsub__(self, other):
        return A(other - self.__data)

    def __rmul__(self, other):
        return A(other * self.__data)

    def __rtruediv__(self, other):
        if self.__data != 0:
            return A(other / self.__data)
        else:
            return A(0)

    def __rmod__(self, other):
        if self.__data != 0:
            return A(other % self.__data)
        else:
            return A(0)

def main():
    object1 = A(1)
    object2 = A(2)
    
    result = object1 + object2  # 내부적으로는 object1.__add__(object2) 호출
    result = object1 - object2
    result = object1 * object2
    result = object1 / object2
    result = result % object2
    result.getter()  # 0.5
    print("--- Reflected 연산자 테스트 ---")
    r_add = 10 + object1  # object1.__radd__(10) 호출
    r_add.getter()        # 11
    
    r_sub = 10 - object1  # object1.__rsub__(10) 호출
    r_sub.getter()        # 9
main()
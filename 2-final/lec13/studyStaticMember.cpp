#include<iostream>

class Counter{
    public:
        static int count; //실존채는 이것이 아님. 그냥 존재만 한다고 언급하는것

        Counter() {++count; }
        ~Counter() { --count; }
        static int get() {return count; }
        
};

int Counter::count = 0; // 실존체는 이것이다.
//static 멤버 자체는 클래스 자체가 가지고 있어야한다.
int main(){
    printf("%d\n", Counter::count); //0
    Counter a, b;
    printf("%d\n", Counter::count); //2
    Counter::count = 4;
    printf("%d\n", Counter::count); //4
    printf("%d\n", Counter::get()); //4

    return 0;
}
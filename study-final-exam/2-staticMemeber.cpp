#include<iostream>


class Counter{
    public : 
    static int count; //클래스 안에서는 선언만 하는데 이것이  실존체는 아님
    Counter() {++count;}
    ~Counter() {--count;}
    static int get(){
        return count;
    }
};

//클래스 외부에서 다시 정의한다
int Counter::count = 0;

int main(void){
    printf("%d\n", Counter::count);
    Counter a, b;
    printf("%d\n", Counter::count); // 2
    printf("%d\n", Counter::get());//2
}
// value타입, 레퍼런스 타입이 뭐냐
//c는 함수에 넘길 때 값을 copy해서 넘긴다(원본 변경 불가)
//즉, 레퍼런스 타입은 존재하지 않음.

#include<stdio.h>


int fun(int, int);

int main(void){
    int a = 3; int b = 5;
    int r = fun(a, b);
    printf("a = %d, b = %d, r = %d\n", a, b, r);
    return 0;
}

int fun(int a, int b){
    a= 1; b= 2;
    //이곳에서 백날 a, b의 값을 바꿔봤자, 래퍼런스타입이 아니기에,
    //main의 a, b에 영향 0
    //그래서 만들어진게 포인터의 개념
    return a + b;
}
//자바나 python은 함수를 선언과 동시에 정의한다.
//but, c프로그램은 선언따로, 전의따로, 호출따로 해야한다.

#include<stdio.h>

// //1. 프로토타입 선언
int add(int, int);
int factorial(int a);

//main함수 - 프로그램 진입
int main(void){
    //2. 함수 호출(call)
    int r = add(3, 5); //add() 함수 호출
    printf("r: %d\n", r);
    printf("5! = %d\n", factorial(5));

    return 0;
}

//3. 함수 정의
int add(int a, int b){
    return a+b;
}

int factorial(int n){
    if(n<=1) return 1;
    return n * factorial(n - 1 );
}
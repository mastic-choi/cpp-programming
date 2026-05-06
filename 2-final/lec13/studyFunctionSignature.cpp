#include <cstdio>
#include <iostream>
#include <cerrno>
#include <cstring>


//old fashion C style에서는 
int add(int a, int b);           // (1)번 함수
int add(int a, int b, int c);    // (2)번 함수
// 두 함수가 오버로딩 되지 않고, 컴파일 오류가 발생한다


int main(){
    //cpp에서는 
    add(10, 20); // 컴파일러가 자동으로 1번함수 호출
    add(10, 20, 30); //컴파일러가 자동으로 2번 호출
}
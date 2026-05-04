#include<iostream>

using namespace std;

void cSwap(int* p, int* q);
void cppSwap(int& p, int&q);


int main(void){
    int x = 42;


    int* p = &x;    // 포인터: x의 주소를 저장
    // 여기서의 &는 주소를 뜻한다.

    int& r = x;     // 참조: x의 별명(alias), 새로 assgin한 r과 x이 같은 실체를 공유한다.
    //여기서 &는 기존의 x의 reference를 만들겠다 라는 뜻이다.
    //포인터는 그 위치를 저장하는건데
    //레퍼런스는 r의 실체가 된다.


    //int& r; 이런식으로 구현하면 안되고, int& r = x; 이런식으로 선언과 동시에 입력할 것


    printf("%d\n", x);      //42
    printf("%d\n", *p);     //42
    printf("%d\n", r);      //42

    r = 100;                //x값 역시 변경된다.
    printf("%d\n", x);      //100

    int a = 100;
    int b = 324;
    // cSwap(&a, &b); pointer로 구현한 것
    cppSwap(a, b); // 래퍼런스로 구현한것
    printf("a is %d\n", a);
    printf("b is %d\n", b);

    return 0;
}

void cppSwap(int& p, int&q){
    int tmp = p;
    p = q;
    q = tmp;
}
void cSwap(int* p, int* q){
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

#include<stdio.h>

void updateValue(int* x);

int main(void){
    int x = 42;
    int y = 48;
    updateValue(&x); //아직 스콥이 끝나지 않았기 때문에 x는 실존하고, 그 x를 포인팅할 수 있다.
    printf("x        =%d\n", x);
    return 0;
}

void updateValue(int* x){
    *x = 100; //주소에 있는 값을 변경
}

//scoop({}) 이 끝나는 지점에서 그 속에 있는 지역 변수들은 소멸한다
//c는 call-by-value를 사용하기 때문에 다른 함수에서 지역 변수를 불러와서 사용하고 싶을때 쓰는 것이 포인터

//{}를 따르지 않고 {}이 끝나도 변수를 살리고 싶으면 사용하는 것이 static
//static변수는 프로그렘이 시작하면 살아나고, 프로그램이 죽으면 죽는다.
//다른 함수안에 static 변수가 있다고 하자, 이 변수는 그 함수가 호출됐는지와는 무관하게, 프로그렘이 시작하자 마자 static 변수는 태어난다.
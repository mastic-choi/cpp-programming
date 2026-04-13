#include<memory>
#include<stdio.h>
#include<stdlib.h>

int main(void){
    auto a = std::make_shared<int>(99);
    //타입을 정하지 않고 알아서 타입을 정해줘라 -> auto
    //make_shared 공유 가능한 포인터
    auto b = a;
    printf("%d\n", *a); //a는 포인터 이기때문에 디레퍼런싱 해야함
    printf("%d\n", *b); //99
    printf("%d\n", a.use_count()); //a와 b : 총 2개

    b = nullptr; // use_count  감소
    //a가 소멸 될때 비로소 메모리 해제
    a = nullptr;
    return 0;

    auto p = std::make_unique<int>(99);
    // new없이 make unique 사용 (다른곳에서는 접근 x)
    printf("%d\n", *p);
    
    auto p2 = std::move(p);
    //복사는 불가능, 오직 소유권 이전만 가능


    return 0;
}


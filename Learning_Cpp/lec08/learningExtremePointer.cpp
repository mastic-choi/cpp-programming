#include<iostream>
using namespace std;

void func(int n){printf("int\n");}
void func(int* p){printf("ptr\n");}

//클래스 객체 -생성자/소멸자 자동호출
struct Point{int x; int y; };


int main(){
    // cpp 에서는 항상 nullptr을 쓰자ㄴ
    func(nullptr); //ptr
    int* p = nullptr; // cpp 권장
    if(p == nullptr) {/* null임*/}


    // new delete - cpp 동적 할당
    //옛 c스타일
    int* p1 = (int*)malloc(sizeof(int));
    *p1 = 42;
    free(p1);
    //malloc으로 잡았다면 free로 해소
    //cpp 스타일
    int* p2 = new int; // 할당(초기화 없음)
    *p2 = 42;
    delete p2;
    //new로 잡으면 delete로 방출
    Point* pt = new Point{3, 4};
    delete pt;
}

#include<iostream>
using namespace std;

class Student{
    public:
    int age;
    char name[32];

    //생성자 - 클래스 이름과 동일, 변환형 없음
    Student(int a, const char* n){
        age = a;
        strcpy(name, n);
        printf("%s 생성!\n", name);
    }

    Student(int i) : age(i){
        // 기본 생성자(인자 없음)
        //int j; 처럼 선언과 동시에 쓰레기 값을 넣는게 아닌
        // 기본 생성자를 쓰는건 int j = 0; 처럼 선언과 동시에 입력하는것
        // main에 있는 i값을 받아서 Student 객체 선언과 동시에 입력받고 싶으면 기본 생성자에 이런식으로 표현해서 선언한다.
        strcpy(name, "이름없음");
        //age = i(main에 있는 값이라고 해보자.)
        //Student(int i)식으로 기본 연산자에 입력해주지 않으면
        //age = i는 i가 뭔지 모르기 때문에 Student(int i)이런식으로 생성과 동시에 선언해야한다.
    }
    //선언과 동시에 입력해주는것이 fm문법이라고 이해하는것이 필요하다
};

int main(void){
    //int i;
    int j = 30;
    Student s(j);
    //기본 생성자에 j를 던지면서 시작한다.
    return 0;
}
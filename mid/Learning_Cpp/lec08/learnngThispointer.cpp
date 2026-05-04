#include<iostream>
using namespace std;

class Student{
    public :
    int age;
    char name[32];

    //매개변수와 멤버 이름이 같을때 
    void set(int age, const char* name) {
        this -> age = age; //왼쪽에 있는 age는 내가가지고 있던 age고 오른쪽에 있는 age는  parametor로 받은 age다
        //교수 왈 이렇게 쓰지마세요
         strcpy(this -> name, name);
    }
    //python의 self랑 똑같다.
    //그냥 파라미터로 받을때는 int a의 파라미터면 int _a 이런식으로 받아와라 this 쓰지말고
};

class Builder{
    // this pointer보다 이게 더 중요하다(Method Chaining)
    // 사실 이걸 하려고 this pointer를 배운거다
    public :
        int x = 0;
        int y = 0;
        Builder& set_x(int v) { x = v; return *this; }
        Builder& set_y(int v) { y = v; return *this; }
    // 나중에 b.set_x(10).set_y(20)처럼 쓰고 싶으면(연쇄적인 )

    /**
     * void set_x(int v){
     * x = v;}
     * void set_y(int v){
     * x = y;}
     * 이렇게 하면 return void 이기 때문에
     * b.set_x(10).set_y(20) 이런식으로 업데이트 하면 b.set_x(10)에서 return void가 되기 때문에 set_y는 작동하지 않는다.
     * Builder의 래퍼런스(즉 실체 값)로 연쇄 작업을 해야한다.
     * b.set_x(10).set_y(20)일때 b.set_x(10) x가 10으로 바뀐 그 실체에 set_y를 접근 해야하기 때문에 래퍼런스타입으로 return 한다.
     * 
     */
};

int main(){
    Builder b;
    b.set_x(10).set_y(20);// 체이닝
    cout << b.x << " "<< b.y<< endl;
    return 0;

}
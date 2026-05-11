#include <iostream>
class A {
private:
    int data;
public:
    A(int _data = 0) { data = _data; }
    void getter() { std::cout << data << std::endl; }
    // 연속된 대입 연산(예: a += b += c)을 지원하기 위해 객체 자신의 참조(A&)를 반환합니다.
    A& operator+=(const A& other) {
        this->data += other.data;
        return *this;}
    A& operator-=(const A& other) {
        this->data -= other.data;
        return *this;}
    A& operator*=(const A& other) {
        this->data *= other.data;
        return *this;}
    A& operator/=(const A& other) {
        if (other.data != 0) { // 0으로 나누기 방지
            this->data /= other.data;} 
        else {
            std::cerr << "Error: Division by zero" << std::endl;}
        return *this;}
    A& operator%=(const A& other) {
        if (other.data != 0) {
            this->data %= other.data;}
        return *this;}
};

int main() {
    A object1(1);
    A object2(2);
    A result(0);
    result += object1;  // result 내부적으로 result.operator+=(object1) 호출
    result.getter();    // 출력: 1
    result += object2; 
    result.getter();    // 출력: 3
    result -= object1;
    result.getter();    // 출력: 2
    result *= object2;
    result.getter();    // 출력: 4
    result /= object2;
    result.getter();    // 출력: 2
    return 0;
}
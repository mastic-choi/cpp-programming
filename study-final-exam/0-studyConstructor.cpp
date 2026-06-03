#include<iostream>

class Point2D{
    public:
    int x,y;

    Point2D(): x(0), y(0) {} // (1)
    Point2D(int _x, int _y): x(_x), y(_y) {} //(2)
    Point2D(const Point2D& other): x(other.x), y(other.y) {} //(3)

    Point2D& operator= (const Point2D& other){ //(4)
        x = other.x;
        y = other.y;
        return *this;
    }
};

int main(void){
    Point2D a(3, 5); //(2)번 실행
    Point2D b = a; //(3)번 실행
    Point2D c, d; //(1)번 실행
    c = d =a; // =(4)번 실행 체이닝
}
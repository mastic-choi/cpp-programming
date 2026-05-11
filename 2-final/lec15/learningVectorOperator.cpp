#include <iostream>
#include <cstdio>


class Vector2D{
private:
    double x, y;
public:
    Vector2D() : x(0.0), y(0.0) {}
    Vector2D(double _x, double _y) : x(_x), y(_y) {}

    double operator()(int i) const{
        return (i == 0) ? x : y;
    }
    double& operator()(int i){
        return (i == 0) ? x : y;
    }
};

class Matrix2D{
private:
    double data[4];
    //확은 double a, b, c, d;
public:
    Matrix2D(){ //(1)
        data[0] = data[1] = data[2] = data[3] = 0.0; //초기값을 전체 0.0으로 주겠다
    }
    // 아무것도 매개변수를 안주는 생성자도 허용한다는 뜻이다.
    Matrix2D(double _a,double _b,double _c,double _d){ //(2)
        data[0] = _a;
        data[1] = _b;
        data[2] = _c;
        data[3] = _d;
    }
    double& operator()(int i, int j){//A(0, 0) = 1 이런식으로 데이터에 접근하고 싶다.
        //실체가 넘겨야함
        //i = 0, j = 0 -> [0]
        //i = 1, j = 0 -> [1]
        //i = 0, j = 1 -> [2]
        //i = 1, j = 1 -> [3]
        return data[i + 2*j];
        // 통해서 인덱스 계산을 통해서 행렬로 내부적으로 구현했지만 OOP를 통해 외부에서는 Matrix처럼 보이게 해줬다

    }
    double operator()(int i, int j) const{ //double d = A(0.0) 이런식으로 실체를 넘길필요 없이 값만 넘기고 싶다
        return data[i + 2*j];
    }
};

Vector2D operator*(const Matrix2D& A, const Vector2D& x){
    Vector2D ret;
    ret(0) = A(0,0) * x(0) + A(0,1) * x(1);
    ret(1) = A(1,0) * x(0) + A(1,1) * x(1);
    return ret;
}
Vector2D operator*( const Vector2D& x, const Matrix2D& A){
    Vector2D ret;
    ret(0) = A(0,0) * x(0) + A(0,1) * x(1);
    ret(1) = A(1,0) * x(0) + A(1,1) * x(1);
    return ret;
}

std::ostream& operator << (std::ostream& os, const Vector2D A ){
    return os;
}
std::ostream& operator << (std::ostream& os, const Matrix2D b){
    return os;
}

int main(){
    Vector2D v, w(3.0, 1.0);
    Matrix2D A; //(1번 호출)
    Matrix2D B(1.0, 2.0, 3.0, 4.0);
    v(1) = 3.14;
    v = B*w;
    Vector2D z = v*B;

    std::cout << w(0) << std::endl;
    std::cout << w(1) << std::endl;
}
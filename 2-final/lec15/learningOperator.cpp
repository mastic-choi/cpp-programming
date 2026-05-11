#include <iostream>
#include <cstdio>

class Vector{
private:
    double* data;
    int size;

public:
    Vector(int n) : size(n) {data = new double[n](); }
    ~Vector() {
        delete[] data;
    }
    double& operator[](int i) {
        std::cout << "assign: "<< std::endl;
        return data[i]; 
    }
    double operator[](int i) const {
        std::cout << "reading: " << std::endl;
        return data[i];}
};

//이거 reading 안찍히는데 리딩 찍히게 바꾸기  
std::ostream& operator<<(std::ostream& os, const Vector& v){
//test
    return os;
}

int main(void){
    Vector v(3);

    v[0] = 10;
    v[1] = 20;
    v[2] = 30;

    printf("%lf\n", v[1]);
    std::cout << "("<< v[0] << ", " << v[1] << ", " << v[2] << ")"<< std::endl; //test
}
#include<iostream>
#include<memory>

class Vector {
    int* data;
    int size;

public:
    Vector(int n) : size(n) {data = new int[n](); }
    ~Vector() { delete[] data; }


    int& operator[](int i) {return data[i];} 
    // v가 업데이트 될때 사용되는 []에 사용
    int operator[](int i) const {return data[i]; }  
    // v가 업데이트 안되고 오직 value호출에서만 사용
  
};

int main(void){
    Vector v{3};
    v[3] =  30; //실행하는 순간 v가 업데이트(const)
    v[2] =  20;
    v[1] =  10;

    std::cout << v[0] << std::endl;// v는 업데이트 안됨(non const)


}
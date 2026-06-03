#include<iostream>

class Vector{
    public:
    int* data;
    int size;
    Vector(int n) : size(n){
        data = new int[n];
    }
    ~Vector(){
        delete[] data;
    }
    Vector(const Vector& other) : size(other.size){
        data = new int[size];
        memcpy(data, other.data, size * sizeof(int));
    }
    Vector& operator= (const Vector& other){
        if(this == &other){ return *this; } //자기 대입 방지
        delete[] data;
        size = other.size;
        data = new int[size];
        memcpy(data, other.data, size * sizeof(int));
        return *this;
    }

};
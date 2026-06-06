#include<iostream>

class Vector{
private:
    int *data;
    int size;
public:
    Vector(int n) : size(n) {data = new int[n]();}
    ~Vector() {delete[] data;}

    int& operator[](int i) {return data[i]; }
    int operator[](int i) const {return data[i]; }
};
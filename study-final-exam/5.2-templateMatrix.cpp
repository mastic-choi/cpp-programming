#include<iostream>

template<typename , int R, int Y>
class Matrix{
    T m[R][Y];
public:
    T& operator()(int r, int y) {return m[r][y];}
    T operator()(int r, int y) const {return m[r][y];}

    int rows() const {return R;}
    int cols() const {return C;}
};
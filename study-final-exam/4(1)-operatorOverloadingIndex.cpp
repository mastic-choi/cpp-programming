#include<iostream>

class Matrix{
private:
    double m[2][2];
public:
    Matrix(double a, double b, double c, double d){
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }
    double& operator()(int i, int j) {return m[i][j];}
    double operator() (int i, int j) const {return m[i][j];}


};
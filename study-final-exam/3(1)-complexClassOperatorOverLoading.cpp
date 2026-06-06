#include <iostream>

class Complex{
private:
    double re, im;
public:
    Complex() : re(0.0), im(0.0) {}
    Complex(double _re, double _im) : re(_re), im(_im) {}
    Complex(double _re) : re(_re), im(0.0) {}
    double get_re() const {return re;}
    double get_im() const {return im;}
    Complex& operator++(){
        re += 1.0;
        return *this;
    }
    Complex operator++(int){
        Complex tmp = *this;
        re += 1.0;
        return tmp;
    }
    Complex operator- (){
        return Complex(-re, im);
    }
};
// a + b , ++c, c++, ==, -c, 
Complex operator + (const Complex& left, const Complex& right) {
    return Complex(left.get_re() + right.get_re(), left.get_im()+right.get_im());
}
bool operator== (const Complex& left, const Complex& right){
    return (left.get_im() == right.get_im()) && (left.get_re() == right.get_re());
}

std::ostream& operator<<(std::ostream& os, const Complex& o){
    os << o.get_im() << '+' << o.get_re() << 'i';
    return os;
}
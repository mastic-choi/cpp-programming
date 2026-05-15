#include <iostream>
#include <numeric>
#include <cassert>
//Fraction (분자, 분모)
class Fraction{
public:
    Fraction(int numerator, int denominator) {
        assert(denominator != 0 && "Error: Denominator cannot be zero!");
        num_ = numerator;
        den_ = denominator;
        reduce();
    }

    Fraction operator+(const Fraction& rhs) const{
        Fraction result( (num_ * rhs.den_) + (rhs.num_ * den_), den_ * rhs.den_);
        result.reduce();
        return result;
    }
    Fraction operator-(const Fraction& rhs) const{
        Fraction result( (num_ * rhs.den_) - (rhs.num_ * den_), den_ * rhs.den_);
        result.reduce();
        return result;
    }
    Fraction operator*(const Fraction& rhs) const{
        Fraction result((num_ * rhs.num_),(den_ * rhs.den_));
        result.reduce();
        return result;
    }
    Fraction operator/(const Fraction& rhs) const{
       Fraction result((num_ * rhs.den_),(den_ * rhs.num_)); 
       result.reduce();
       return result;
    }
    Fraction operator-() const{
        return Fraction(-num_, den_);
    } // 단항 부호 반전
    Fraction& operator+=(const Fraction& rhs){
        *this = *this + rhs;
        return (*this);
    }
    Fraction& operator-=(const Fraction& rhs){
        *this = *this - rhs;
        return (*this);
    }    
    bool operator==(const Fraction& rhs) const{
        return (num_ * rhs.den_ == den_ * rhs.num_);
    }
    bool operator!=(const Fraction& rhs) const{
        return (num_ * rhs.den_ != den_ * rhs.num_);
    }
    bool operator< (const Fraction& rhs) const{
        return (num_ * rhs.den_) < (rhs.num_ * den_);
    }

    explicit operator bool() const{
        return (num_ != 0);
    }

    int operator[](int index) const {
        if (index == 0) return num_;
        if (index == 1) return den_;
        return 0;
    }

    friend std::ostream& operator << (std::ostream& os, const Fraction& f);

private:
    int num_;
    int den_;
    void reduce(){
        int gcd_ = std::gcd(num_, den_);
        num_ /= gcd_;
        den_ /= gcd_;
        if (den_ < 0 ){
            den_ = -den_;
            num_ = -num_;
        }
    }
};

std::ostream& operator << (std::ostream& os, const Fraction& f){
    if (f.den_ == 1){
        os << f.num_ ;
    }else{
        os << f.num_ << '/' << f.den_;
    }
    return os;
}

int main(){
    Fraction a(1, 2);
    Fraction b(1, 3);

    std:: cout << a << " + " << b << " = " << (a+b) << std::endl;
    std:: cout << a << " * " << b << " = " << (a*b) << std::endl;
    std:: cout << a << " == " << Fraction(2, 4) << " : " 
               << std::boolalpha << (a == Fraction(2, 4)) << std::endl;
    if (a) std::cout << a << " is nonzero" << std::endl;
    a += b; 
    std::cout << "a += b : " << a << std::endl;
    std::cout << "분자: " << a[0] << ", 분모: " << a[1] << std::endl;

}

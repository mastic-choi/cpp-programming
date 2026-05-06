#include <iostream>
class Complex{
    private:
        float re, im;
    public:
        //float re, im;
        Complex() :re(0.0f), im(0.0f){}
        Complex(float _re, float _im) : re(_re), im(_im) {}
        //Complex(double re, double im = 0.0) : re(re), im(im){}
        float get_re() const {return re;}
        float get_im() const {return im;}
        void set_re(float _re) {re = _re; }
        void set_im(float _im) {im = _im; }
};
/*
Complex operator+(const Complex& left, const Complex& right) {
    //교수님은 이 방식을 선호
            return Complex(left.re + right.re, left.im + right.im);
        }
*/
Complex operator+(const Complex& left, const Complex& right) {
    //c형식으로 구현된 연산자 오버로딩을 OOP를 적용하여 구현하기 위해 setter getter를 사용해서 구현한
    // 연산자 오버로딩
            return Complex(left.get_re() + right.get_re(), 
                           left.get_im() + right.get_im());
        }
std::ostream& operator << (std::ostream&os, const Complex& c) //ostream은 화면을 객체로서 명시한것
{
    //실체를 받아오고, 그 실체를 수정하고
    os << "("<<c.get_re() << "+" << c.get_im() <<"i)";
    return os;
    // 수정된 실체를 return 한다
}
int main(void){
    Complex a(1.0, 2.0);
    Complex b(3.0, -1.0);


    Complex c = a+b; //a.operator +  (b)

    std::cout << c << std::endl; 
    // 컴파일러는 사용자 정의 된 타입에 대한 출력 방식이 사전 정의되있지 않기 때문에 오류를 출력한다
    // 하지만, 컴파일러를 수정하는것이 불가능하기 때문에 operator <<를 수정한다.
    //
    printf("c: (%f, %f)\n", c.get_re(), c.get_im());
    return 0;
}
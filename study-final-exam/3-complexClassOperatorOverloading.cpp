#include <iostream>
class Complex{
public:
    double re, im;
    Complex() : re(0), im(0){}
    Complex(double _re, double _im) : re(_re), im(_im){}
    Complex(double _re) : re(_re), im(0.0) {}

    Complex& operator=(const Complex& other){
        re = other.re;
        im = other.im;
        return *this;
    }
    Complex operator+(const Complex& other){
        return Complex(other.re+re, other.im+im);
    }
    Complex operator-(const Complex& other){
        return Complex(re - other.re, im - other.im);
    }
    Complex operator-(){
        return Complex(-re, -im);
    }

};









// =====================================================================
// 자네들은 이곳에 Complex 클래스를 구현한다.
// 힌트 따위는 없다. 배운 대로 정확하게 구현하도록.
// =====================================================================



// =====================================================================
// 아래 main 함수는 절대 수정하지 말 것.
// =====================================================================
int main(void) {
    // 1. 상수 객체 생성 (이 객체들을 대상으로 한 연산에서 컴파일 에러가 발생하면 0점)
    const Complex c1(1.0, 2.0);
    const Complex c2(3.0, -1.0);

    // 2. 이항 연산자 및 부호 반전 테스트
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = -c1;
    bool isEqual = (c1 == c2);

    // 3. 증감 연산자 테스트 (비상수 객체)
    Complex c7(3.0, 4.0);
    Complex c8 = ++c7; 
    Complex c9 = c7++; 

    // 4. 결과 검증
    std::cout << "--- 연산 결과 검증 ---" << std::endl;
    
    // c3 (c1 + c2) -> 4.0 + 1.0i
    std::cout << "c1 + c2 = " << c3.re << " + " << c3.im << "i" << std::endl; 
    
    // c4 (c1 - c2) -> -2.0 + 3.0i
    std::cout << "c1 - c2 = " << c4.re << " + " << c4.im << "i" << std::endl; 
    
    // c5 (c1 * c2) -> 5.0 + 5.0i
    std::cout << "c1 * c2 = " << c5.re << " + " << c5.im << "i" << std::endl; 
    
    // c6 (-c1) -> -1.0 - 2.0i
    std::cout << "-c1 = " << c6.re << " + " << c6.im << "i" << std::endl; 
    
    // isEqual -> 0 (false)
    std::cout << "c1 == c2 : " << (isEqual ? "true" : "false") << std::endl;

    // 증감 연산자 결과 확인
    // c8 (전위 증가 결과) -> 4.0 + 4.0i
    std::cout << "++c7 result = " << c8.re << " + " << c8.im << "i" << std::endl; 
    
    // c9 (후위 증가 반환값) -> 4.0 + 4.0i (증가되기 전의 값 반환)
    std::cout << "c7++ return = " << c9.re << " + " << c9.im << "i" << std::endl; 
    
    // c7 (후위 증가 이후 최종 c7의 상태) -> 5.0 + 4.0i
    std::cout << "Final c7 = " << c7.re << " + " << c7.im << "i" << std::endl; 

    return 0;
}
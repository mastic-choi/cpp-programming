#include <iostream> 
class A{
private:
    int data;
public:
    A(int _data = 0) {data = _data; }
    void getter(){std::cout << data << std::endl; }
    friend A operator + (const A& a1, const A& a2 );
    friend A operator - (const A& a1, const A& a2 );
    friend A operator * (const A& a1, const A& a2 );
    friend A operator / (const A& a1, const A& a2 );
    friend A operator % (const A& a1, const A& a2 );
};
A operator + (const A& a1, const A& a2 ) { return  A(a1.data + a2.data);}
A operator - (const A& a1, const A& a2 ) { return  A(a1.data - a2.data);}
A operator * (const A& a1, const A& a2 ) { return  A(a1.data * a2.data);}
A operator / (const A& a1, const A& a2 ) { return  A(a1.data / a2.data);}
A operator % (const A& a1, const A& a2 ) { return  A(a1.data % a2.data);}

int main(){
    A object1(1);
    A object2(2);
    A result = object1 + object2; 
    result.getter();// 3
    result = result - object1;
    result.getter();// 2
    result = result * object2;
    result.getter();// 4
    result = result / object1;
    result.getter(); // 4
    result = result % object2;
    result.getter(); // 0   
}
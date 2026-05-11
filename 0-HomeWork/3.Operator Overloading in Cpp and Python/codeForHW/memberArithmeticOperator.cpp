#include <iostream> 

class A{
private:
    int data;
public:
    A(int _data = 0) {data = _data; }
    void getter(){std::cout << data << std::endl; }
    A operator + (const A& a2 ){
    return  A(data + a2.data);}
    A operator - (const A& a2 ){
    return  A(data - a2.data);}
    A operator * (const A& a2 ){
    return  A(data * a2.data);}
    A operator / (const A& a2 ){
        if (a2.data != 0){
            return  A(data / a2.data);}
        else {
            return A(0);}  
}
    A operator % (const A& a2 ){
        if (a2.data != 0){
            return  A(data % a2.data);}
        else {
            return A(0);}
    }
};
int main(){
    A object1(1);
    A object2(2);

    A result;

    result = object1 + object2; 
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
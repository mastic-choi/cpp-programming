#include<iostream>

template<typename T>
void swap(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;  
}

template<typename T, int n>
void repeat(T val){
    for(int i = 0; i<n; i++){
        std::cout<<val<<"\n";
    }
}

template<typename T, typename U>
class Pair{
private:
    T first;
    U second;
public:
    Pair(T _first, U _second) : first(_first), second(_second) {}
    void print() const{
        std::cout << first << ", " << second << "\n";
    }
};

int main(void){
    
    Pair<int, std::string> p1(4, "안녕");
    p1.print();
}
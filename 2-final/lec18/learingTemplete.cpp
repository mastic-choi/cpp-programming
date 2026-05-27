#include<iostream>

template <typename T, int N>
class Vector{
    T data[N];
public :
    Vector() {}
    T& operator()(int i)    {return data[i];}
    T operator()(int i) const {return data[i];}

    int size() const {return N;}


};
template <typename T, int N>
std::ostream& operator<<(std::ostream& os, const Vector<T,N>& v){
    os << "( ";
        for(int i = 0; i < N; ++i)
            os << v(i) << " ";
    os << ")";
    return os;
}
using Vec3i = Vector<int, 3>;
using Vec2f = Vector<float, 2>;
using Vec3s = Vector<std::string, 3>;

int main(void){
    Vec3i v;
    v(0) = 3;
    v(1) = -2;
    v(2) = 123;
    Vec2f x;
    x(0) = 10.0f; x(1) = -0.1f;
    Vec3s z;
    z(0) = "국민"; z(1) = "대학교"; z(2) = "화이팅";
    std::cout << v << std::endl;
    std::cout << x << std::endl;
    std::cout << z << std::endl;

    return 0;
}
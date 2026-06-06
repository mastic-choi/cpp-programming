#include<iostream>
#include <string>
template<typename T, int R, int C>
class Matrix{
    T data[R][C] = {};
    public:
    T& operator()(int r, int c) {return data[r][c];}
    const T& operator()(int r, int c) const {return data[r][c];}

    int rows() const {return R;}
    int cols() const {return C;}
};

template<typename T, int N>
class Vector{
    T data[N] = {};
    public:
    T& operator()(int i) {return data[i]; }
    const T& operator()(int i) const {return data[i]; }
    int size() const { return N;  }
};

template<typename T, int N>
std::ostream& operator<<(std::ostream& os, const Vector<T, N>& v){
    os << "(";
    for (int i = 0; i < N; i++){
        os << v(i) << " ";
    }
    os<< ")";
    return os;
}

using Vec3i = Vector<int, 3>;
using Vec2f = Vector<float, 2>;
using Vec3s = Vector<std::string, 3>;
int main()
{
	Vec3i	v;
	v(0) = 3;  v(1) = -1,  v(2) = 2;
	std::cout << "v = " << v << std::endl; 

	Vec2f   x;
	x(0) = 10.0f, x(1) = -0.1f;
	std::cout << "x = " << x << std::endl;

	Vec3s   s;
	s(0) = "Kookmin";   s(1) = "University",   s(2) = "C++ Programming";
	std::cout << "s = " << s << std::endl;

	return	0;
}

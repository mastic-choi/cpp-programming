#include<iostream>
using namespace std;

class Point{
    private:
        int age;
        int c;
        int& r;
    public:
        Point(int age, int c, int& rrr)
            : age(age), 
            c(c), 
            r(rrr)
            {}
        void update_r(){
            r = 300;
        }
};

int main(){
    int i = 32;
    int c = 23;
    int rrr = 122313;
    cout << "rrr = " << rrr << endl;
    
    Point p(i, c, rrr);
    p.update_r();
    cout << "rrr = " << rrr << endl;

    return 0;
}
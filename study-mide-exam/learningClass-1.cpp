#include <iostream>
#include <string>

using namespace std;


class SimpleBooks{
    protected:
        string title;
        int price;

    public:
        SimpleBooks(string t, int p){
            title = t;
            price = p;
            cout << "생성자 호출! 책이 등록되었습니다." << endl;
        }

        void printinfo(){
            cout << "title : " << title << endl << "price : " << price << endl;
        }
};

int main(void){
    SimpleBooks s("나는 나비", 2000);
    s.printinfo();
    return 0;
}
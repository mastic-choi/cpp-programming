//생성자와 소멸자

#include<iostream>
#include <cstdlib>

using namespace std;

class SimpleShelf {
    protected:
        int* price;

    public:
        SimpleShelf(int cap){
            price = (int*)malloc(cap * sizeof(int));
            cout << cap << "칸 짜리 책장이 동적 할당되었습니다!"<< endl;

        }
        ~SimpleShelf(){
            free(price);
            cout << "책장 메모리가 안전하게 해제되었습니다!" << endl;
        }
};

int main(void){
    cout << "--- 프로그램 시작 ---" << endl;
    
    SimpleShelf myShelf(5); 

    cout << "--- 프로그램 종료 ---" << endl;
    
    return 0;
}



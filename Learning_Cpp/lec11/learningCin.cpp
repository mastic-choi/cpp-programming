#include<iostream>
#include<string>

using namespace std;


int main(void){
    //canf vs std::cin
    // c언어의 입력 방식 
    int a; double b;
    scanf("%d %lf", &a, &b);
    cout << "a = "<< a << "\nb = "<< b << endl;

    // scanf("%d", a); <- 오류 발생
    int a_; double b_;
    cin>> a_ >> b_;
    cout<< "a_ = " << a_<< "\nb_ = " << b_ << endl;




    // cin으로 >> 입력 직후, getline 주의!
    string name;
    int age ;
    cin >> age;// 버퍼에 \n이 남음, 즉 '\n'을 제거해줘야함
    cin.ignore(); // 버퍼 속 \n 제거
    getline(cin, name); // enter 치기 전까지의 내용을 싹다 박아서 쓰겠다
    cout<< "age = " << age << "\nname = " << name<< endl;


    return 0;

}
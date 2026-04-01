#include<iostream>
using namespace std;
//class에 지역함수에 const 붙여서 선언하고 
//그걸 밖에서 const로 호출하는 방법을 시험으로 출제한다고 하시네요.
class Student{
    public:
    void set_arr() {
    //배열의 이름은 주소이기 때문에 작동가능.
        for(int i = 0; i<100; ++i){
            arr[i] = i;
    }}
    void print_arr() const{
    // 이제 print_arr()로 선언된 함수는 지역 함수로 변환 됐다.
    // 멤버 함수 이지만 const로 선언하고 싶으면 void print_arr() const{} 식으로 선언한다.
        for (int i = 0; i <100; ++i){
            cout << "arr["<< i<<"] = "<< arr[i] << endl;
    }}
    public:
    int arr[100];
};
void swap(int& a, int& b){
    //&를 붙이면 이것을 call by value가 아닌, reference로 받겠다 라는뜻.
    int tmp = a;
    a = b;
    b = tmp;
}
void set_z(int& x){
    x = 50;
}

void set_arr(int arr[100]){
    //배열의 이름은 주소이기 때문에 작동가능.
    for(int i = 0; i<100; ++i){
        arr[i] = i;
    }
}

void print_arr(const int arr[100]){
    //print하는것은 수정없이 복사만 안전하게 수행하고 싶다. 이때 수행하는 것이 const
    //매우 중요하다!
    for (int i = 0; i <100; ++i){
        cout << "arr["<< i<<"] = "<< arr[i] << endl;
    }

}

void my_another_func(const Student& s){
    //const Student& s로 넘기면 컴파일 오류가 발생!!
    //학생들은 "어? const를 넣으니깐 오류가 생기네? const 삭제" -> 이러면 취업 불가능...
    //절대 컴파일 하려고 const 삭제 하지 마시오...
    s.print_arr();
    // class의 멤버 함수를 const로 불러와서 사용하고 싶으면 void print_arr() const{} 식으로 선언한다.
    // 이제 void print_arr() const{}로 선언하고 그 class를 const로 호출하면, 오류가 발생 안하고 호출된다.
}
int main(void){
    Student s;
    s.set_arr();
    s.print_arr();
    //이렇게 하면 선언 및 실행이 잘됨
    int x = 10, y = 20;
    swap(x, y);
    cout << "x : "<< x << "\ny : "<< y << endl;
    //const 참조란, 읽기 전용으로 원본을 참조한다. 복사 없이 안전하게 전달
    int z = 24;
    int arr[100];
    set_arr(arr);
    print_arr(arr);
    set_z(z);
    const int& p = z;
    cout << "p = "<< p << endl;
    // p = 100; 컴파일 오류 (const로 선언됐기 때문에 수정 불가!!)
    return 0;

}

// read only 객체는 반드시 const붙여라, 안그려면 '무조건!' 나중에 const로 호출하면 문제가 생긴다!!!
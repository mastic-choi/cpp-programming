#include<iostream>
#include<cerrno>
#include<cstring>
#include<fstream>
using namespace std;

int main(void){
    cout << "Hello World!";
    ifstream file("없는파일.txt");
    if(!file){
        cerr << "오류: 파일을 열 수 없음\n";
        cerr << "errno "<< errno
             << ": " << strerror(errno) << "\n";
    }

    clog << "[DEBUG] 파일 열기 시도 \n";
}

// a.exe 2> err.txt 로 하면, 에러 파일을 다른쪽으로 넘길수 있다
// 이것이 왜 가능하냐? 터미널도 파일, 원래 터미널로 갈 파일을 다른곳으로 넘긴것 뿐이다.

// a.exe > aaa.txt로 하면 원래 터머닐에 찍힐 것들이 즉, 정상적인 print가 aaa.txt 찍힌다.

//./a > aaa.txt 2> err.txt   이렇게 하면, 정상 출력(Hello World)와 에러코드를 분류 해서 리다레팅이 가능하다.
//원래 둘은 분리 되있었는데 terminal에서 그냥 같이 출력됐던거 뿐이다.
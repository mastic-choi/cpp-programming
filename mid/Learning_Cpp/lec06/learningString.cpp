#include<iostream>
//#include<cstdio> 
//stdio.h라고 써도 괜찮지만 앞에c를 붙이고 뒤에 .h를 빼고 써라(ex. string.h -> cstring)
#include<string>



int main(void){
    std::printf("Hello World!");
    //함수가 std 네임스페이스에 배치된다.

    //string 선언과 초기화
    std::string s1;
    std::string s2 = "Hello";   //문자열 리터럴로 초기화
    std::string s3("World");    //생성자 호출
    std::string s4(5, 'A');     //"AAAAAA"
    std::string s5 = s2;        // 복사

    //기본 정보 조회
    s2.size();                  // 5(바이트 수)
    s2.length();                // 5(size()와 동일)
    s2.empty();                 // empty
    s2[0];                      //'H'
    s2.at(0);                   //'H'
    s2.front();                 //'H'
    s2.back();                  //'o'

    std::string a ="Hello";
    std::string b =" World";

    std:: string c = a + b;     //"Hello World"
    a += "!";

    a == b; //false(C에서 불가능. C에서는 문자열이 말 그대로 배열, 두갤 비교하는게 아니라 배열의 이름인 포인터를 비교한다)
    a < b; //사전순 비교

    c.substr(6);                //"World"
    c.substr(0, 5);             //"Hello"
    c.find("World");            //6 위치찾음
    c.find("aksfd");            //못찾음
    // c.contains("Hello");     // return true; C++23
    //string을 c로 넘길때 c_str()을 쓰면 된다!
    std::printf("%s\n", c.c_str());
    return 0;


}
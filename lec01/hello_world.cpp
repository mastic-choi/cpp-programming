#include<iostream>
/** include <- iostream 코드를 삽입(복사 붙여넣기)하겠다 */

int main(){
    std :: cout<< "Hello World" << std::endl;
    return 0;
}

/**g++ -E hello_world.cpp -o hello.i  위 명령어를 실행했을때,
 * hello.i라는 파일을 만들게 됨. 
 * 이 hello.i는 iostream을 복사 붙여넣기 한 전체코드임.
*/


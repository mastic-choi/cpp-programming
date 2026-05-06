#include<stdio.h>

int main(void){
    char s1[256] = "Hello";
    // memory : H e l l o \0 ? ? ?
    // 이때 \0는 이 문자열이 종료했다는 NULL 종료자
    char s2[256] = "Hello";
    if (s1 == s2){
        printf("두 문자가 동일합니다.\n");
    }else{
        printf("동일 문자가 아닙니다.\n");
    } // 동일 문자가 아닙니다가 출력된다.
    //Why? 앞서 말한것처럼 array의 이름은 주소를 뜻한다.
    //즉, 속 내용은 똑같아도, 주소가 다르기 때문에 bool은 거짓을 출력이다

    //문자열이 동일한지 확인하는 연산은 StringCompare를 통해 진행
    #include<string.h>
    if (!strcmp(s1, s2)){ //만약 두 문자열이 같으면 strcmp의 값은 0이 나온다. 그렇기 때문에 !을 추가해야한다.
        printf("두 문자가 동일합니다.\n");
    }else{
        printf("동일 문자가 아닙니다.\n");
    }
    int n = 12;
    char dst[256];
    char scr[256];
    strlen(s1); //길이를 출력한다
    strcpy(dst, scr); //scr의 값을 dst로 옮긴다.
    strncpy(dst, scr, n);//안전한 copy
    strcat(s1, "!"); // 뒤에 붙이기
    strcmp(s1, s2); //두 문자열 비교

    return 0;
}
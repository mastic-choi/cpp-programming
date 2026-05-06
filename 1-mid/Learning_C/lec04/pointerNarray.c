#include<stdio.h>
#include<string.h>

int main(void){
    char s1[256] = "Hello";
    int arr[5] = {10, 20, 30, 40, 50};
    printf("s1 is %s \n", s1);
    char* p = s1; // char* p = &s1[0];
    //s1 문자열의 첫번째 열의 주소를 받는다
    p[0] = 'h'; 
    p += 1;// 포인터 주소 변경을 통해 다음 컨텐츠로 가라고 명령
    *p = 'E';
    int* tmp = arr; //int* tmp = &tmp[0];
    tmp[0] = -10;
    tmp += 1; // 다음 컨텐츠로 가라(실제로는 인티저의 크기 즉, 4바이트 증가시킨다)
    *tmp = 23;
    /*
    tmp += 1; 
    tmp = 23;
    이딴 문법 쓰지마시요..
    */

    printf("modified s1 is %s \n", s1);
    printf("modified arr is {");
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("}\n");

    return 0;
}
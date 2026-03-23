#include<stdio.h>
#include<stdlib.h>
int main(void){

    int arr[100];
    int* s= (int*)malloc(sizeof(int)*100); 
    //int의 사이즈인 4바이트를 곱하기 100
    //malloc은void를 리턴하기때문에 (int*)로 typecasting

    void* p = malloc(8000);//이렇게 쓰는사람과 거리를 두세요.
    // malloc의 return 값은 반드시 void값이어야한다.
    // 위치만 정한것이지! 어떻게 사용하는지는 니 맘이다 ~> void리턴
    int* pi = (int*) p;
    //pi[0]~ p[1999]

    float* pf = (float*) p;
    // pf[0] ~ pf[1999]

    double* pd = (double*)p;
    //
    free(p); //반드시 메모리 방출
    //void포인터로 그곳의 위치는 받았지만, 그 위치의 이름은 정해지지 않음(void)
    //그래서 system에서 자동으로 메모리 방출을 안하기 때문에 반드시 메모리 방출을 수동으로 해줘야한다.
    free(s); 

    return 0;


}
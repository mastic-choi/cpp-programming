#include<stdio.h>

void updateValue(int* x);
int sum(int, int);

int main(void){
    int x = 42;
    int y = 48;

    int z = sum(x, y);
    int p = sum(x, y);
    printf("z        =%d\n", z);
    printf("p        =%d\n", p);

    return 0;
}

void updateValue(int* x){
    *x = 100; //주소에 있는 값을 변경
}

int sum(int a, int b){
    static int count = 100;
    // static int count;
    // int count = 100;
    count += 1;
    //두 코드의 차이를 알아보자
    //첫번째 방식에서 static이 선언 된 줄은 한번만 실행된다.
    //하지만, count에 값을 집어넣는 연산은 게속 반복되기 때문에 count+=1이 무력화 되며 계속해서 100을 집어넣는다.
    return a + b + count;
}



/*
int c;
c = 100;과 

int c =100;은 서로 다르다.

두 방법은 결과는 같지만, 방식이 다르다
두 번째 방법은 c를 초기화 한 동시에 그 공간에 c를 집어 넣는 것이다.
첫 번째 번째 방법은 int c; (선언): 메모리에 c라는 이름의 빈 방만 만듭니다.
c = 100; (대입): 이미 만들어진 방에 100이라는 값을 집어넣습니다.




*/
#include<stdio.h>

void dataUpdate(int* px);
void arrayUpdate(int aaa[], int size);

int main(void){
    int newArray[5] = {1, 2, 3, 4, 5}; // 배열로 만들면 값들은 반드시 메모리 상에서 옆에 위치하게된다.
            //인덱스     0, 1, 2, 3, 4
    int x = 10;
    printf("newArray[0] is %d\n", newArray[0]);
    printf("x is %d\n", x);
    int n = sizeof(newArray)/sizeof(newArray[0]); //array의 길이를 계산하는방법
    dataUpdate(&x);
    arrayUpdate(newArray, n); 
    //포인터를 사용하지 않았기 때문에 논리상 newArray[0] 은 변경되지 않아야함.
    //하지만, C계열에서 배열의 이름은 그 속에 포인터를 내포하고 있다. 즉, array의 데이터 이동은 포인터 사용없이 가능하다.

    printf("modified newArray[0] is %d\n", newArray[0]);
    printf("modified x is %d\n", x);
    
    //sizeof는 메모리상에서 얼마나 차지하고 있나는 보여줌
    printf("sizeof(int) = %d\n", sizeof(int)); 
    printf("sizeof(newArray) = %d\n", n); 
    printf("elements of newArray is ");
    for (int i = 0; i <n; i++){
        printf("%d, ", newArray[i]);
    }

    return 0;

}

void dataUpdate(int* px){
    *px =20;
}

void arrayUpdate(int aaa[], int size){
    aaa[0] = -10;
}


#include<iostream>


int add(int a, int b) { return a+b; }
int sub(int a, int b) { return a-b; }
int main(void){
    int (*op)(int, int);

    op = add;
    printf("%d\n", op(3, 5));
    op = sub;
    printf("%d\n", op(5, 3));
}
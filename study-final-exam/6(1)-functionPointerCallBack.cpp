#include<iostream>

int add(int a, int b) {return a+b;}
int sub(int a, int b) {return a-b;}

int apply(int a, int b, int (*op)(int a, int b)){
    return op(a, b);
}

int main(void){
    int result = apply(3, 4, add);
}


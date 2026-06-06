#include<iostream>
#include<cstdlib>
#include<algorithm>

int cmp_asc(const void* a, const void* b){
    return *(int*) a - *(int*) b;
    // 오름차순
}
int cmp_desc(const void* a, const void* b){
    return *(int*) b - *(int*) a;
    //내림차순
}
int main(void){
    int arr[] = {5, 2, 8, 1, 9};
    qsort(arr, 5, sizeof(int), cmp_asc);
    // arr -> 1 2 5 6 8

    qsort(arr, 5, sizeof(int), cmp_desc);
    // arr -> 9 8 5 2 1
}
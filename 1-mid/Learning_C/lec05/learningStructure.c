// 구조체는 연속적이라는 부분에서 동일한데, 여러 데이터 타입을 묶었다는점에서 다르다.

#include<stdio.h>
#include<string.h>
// 새로운 타입을 정한다 typedef
typedef struct //새로운 구조체 정의
{
    char name[50];
    int student_id;
    double gpa;
    }Student; //타입 이름
int main(void){

    // 구조체 변수 생성 및 초기화
    Student s1 = {"김철수", 20230841, 3.8};
    Student s2;


    //접근
    strcpy(s2.name, "이영희");
    s2.student_id = 20230002;
    s2.gpa = 3.5;
    printf("%s: %.1f\n", s1.name, s1.gpa);
    Student* s = &s1;
    printf("%-10s: %d %.2f\n",
            s -> name,      //(주의)넘겨받은건 이렇게 사용한다.
            s->student_id,
            s->gpa);
}


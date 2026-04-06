#include<iostream>
using namespace std;

enum class Season{
    //c의 형식을 쓰지마시고, cpp 형식의 enum을 사용해라
    SPRING,
    SUMMER,
    FALL,
    WINTER,
};

int main(){
    int direction = 0;
    if (direction == 0) {
        //0이 북쪽? 동쪽?
        //코드잘 못짜는걸 만천하게 자랑하고 싶으면 이렇게 써라
    }
    enum Direction{NORTH, EAST, SOUTH, WEST};
    Direction dir = NORTH;
    if (dir == NORTH){
        //의도가 명확함
    }
    // enum을 꼭 쓰셔라
    Season s = Season::SUMMER;
    switch (s) {
        case Season::SPRING: printf("봄\n");   break;
        case Season::SUMMER: printf("여름\n"); break;
        case Season::FALL:   printf("가을\n"); break;
        case Season::WINTER: printf("겨울\n"); break;
    }


}
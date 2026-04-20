#include<iostream>
#include<cstdlib>
#include<string>

enum class CurrentStatus {READY, DISPENSING, ERROR};

class VedingMachine{
    protected:
        int count; //판매할 상품의 개수
        int* produ; //판매할 상품의 가격을 저장할 장소
        CurrentStatus cs;

    public:
        VedingMachine(int count_){
            //생성자
            count = count_;
            produ = (int*)malloc(count * sizeof(int));
            cs = CurrentStatus::READY;
        }
        ~VedingMachine(){
            //소멸자
            free(produ);
        }
        VedingMachine& getPrice(int ind, int price){
            produ[ind] = price;
            return *this;
        } 
        void copyVM(const VedingMachine& s){
            count = s.count;
            //produ는 list 이기때문에 변수명이 그 자체로 포인터이다.
            //pointer를 넘겨수면 나중에 소멸자 부분에서 v를 free해주는 순간 v1의 produ도 같이 free 가 된다.(그럼 안된다)
            //넘겨주는걸 연습하자
            for (int i = 0; i < count; i++){
                produ[i] = s.produ[i];
            }
                
        }
        void printVM(void){
            std::cout << "Veding Machine :";
            for (int i = 0; i < count; i++){
                std::cout << " idx = " << i << " price = " << produ[i]<< ",";
            }
            std::cout << std::endl;
        }
        

};


int main(void){
    VedingMachine v(3);
    v.getPrice(0, 1000).getPrice(1, 2000).getPrice(2, 3000);
    VedingMachine v1(3);
    v1.copyVM(v);
    v1.printVM();

}
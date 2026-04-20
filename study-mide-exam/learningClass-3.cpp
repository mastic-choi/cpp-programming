//this pointer 학습

#include<iostream>
#include<cstdlib>

class SmartCart{
    protected:
        //멤버 변수 선언함
        int capacity;
        int* prices;
    public : 
        SmartCart(int cap){
            //생성자
            capacity = cap;
            prices = (int*) malloc (cap*sizeof(int));
            std::cout << capacity <<"칸 짜리 스마트 카트 생성 완료!" << std::endl;
        }
        ~SmartCart(){
            //소멸자
            free(prices);
            std::cout << "카트 메모리 안전하게 반납 완료!" << std::endl;
        }
        SmartCart& setPrice(int index, const int& p){
            if (index < 0 || index >= capacity){
                std::cerr << "[에러] 카트의 범위를 벗어났습니다!" << std::endl;
                return ;
            }else {
                prices[index] = p;
            }
            return *this;
        }
        void printCart(){
            for (int i = 0; i < capacity; i++){
                std::cout << "--- 장바구니 내역---" << std::endl;
                std::cout << i << "번 상품 가격: " << prices[i] << std::endl;
            }
        }

};


int main(void){
    SmartCart s(3);
    s.setPrice(0, 1500).setPrice(1, 2000).setPrice(5, 3000);
    s.printCart();

    return 0;
}
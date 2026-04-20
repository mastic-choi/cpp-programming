#include<iostream>
enum class CurrentStatus {STANDBY, FLYING, CRASHED};

class Drone{
    protected:
        int max_count;
        int* listofCargo;
        CurrentStatus cs;

    public:
        Drone(int _max){
            max_count = _max;
            listofCargo = (int*) malloc (max_count*sizeof(int));
            cs = CurrentStatus::STANDBY;
        }//end of 생성자
        ~Drone(){free(listofCargo);};

        Drone& loadPackage(int idx, int value){
            if(idx > (max_count - 1)){
                std::cerr<< "[경고] 적재 범위를 초과했습니다!\n";
                cs = CurrentStatus::CRASHED;
            }else{
                listofCargo[idx] = value;
            }
            return *this;
        }

        void cloneData(const Drone& d){
            this->max_count = d.max_count;
            this->cs = d.cs;
            for (int i = 0; i < max_count; i++){
                listofCargo[i] = d.listofCargo[i] ;
            }
        }
        void printDrone(){
            std::cout << "상태: " ;
            switch(cs){
                case CurrentStatus::STANDBY : std::cout << "STANDBY" << std::endl; break;
                case CurrentStatus::FLYING : std::cout << "FLYING" << std::endl; break;
                case CurrentStatus::CRASHED : std::cout << "CRASHED" << std::endl; break;
            }
            std::cout << "적재물: " ;
            for (int i = 0; i < max_count; i++){
                std::cout << " " << listofCargo[i];
            }
        }

};

int main() {
    // 3칸짜리 Alpha 드론 생성
    Drone alpha(3);
    
    // 정상 적재 (연속 호출)
    alpha.loadPackage(0, 100).loadPackage(1, 200).loadPackage(2, 300);
    
    // 고의적 에러 유발: 3칸짜리 드론에 3번 인덱스(4번째 칸) 접근
    alpha.loadPackage(3, 400); 

    std::cout << "\n[ Alpha 드론 정보 ]" << std::endl;
    alpha.printDrone();

    // 3칸짜리 Beta 드론 생성
    Drone beta(3);
    
    // Alpha 드론의 데이터를 Beta로 안전하게 복제
    beta.cloneData(alpha);

    std::cout << "\n[ Beta 드론 정보 ]" << std::endl;
    beta.printDrone();

    return 0; // 프로그램 종료 시 메모리 반납 과정에서 터지지 않아야 최종 성공입니다!
}
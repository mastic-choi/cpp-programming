#include<iostream>
#include<cstdlib>

enum class CurrentStatus {LOCKED, OPENDED, ALERT};

class SmartVault {
    public:
        //생성자
        SmartVault(int size_){max_size = size_; cs = CurrentStatus::LOCKED; pw = (int*) malloc (max_size * sizeof(int));};
        int get_max_size() const {return max_size;};
        void printPW(){
            std::cout << "===printing pw===" << std::endl;
            for(int i = 0; i < max_size ; i++){
                std::cout << pw[i] << " ";
            }
            std::cout<<std::endl;
        }
        int* get_pw() const {return pw;};
        CurrentStatus get_currentStatus() const {return cs;};
        SmartVault& setSecret(int _idx, int value){
            if (_idx > (max_size-1)){
                std::cerr << "경고 허용범위를 초과했습니다.\n" ;
                cs = CurrentStatus::ALERT;
            } else {
                pw[_idx] = value;
            }
            return *this;    
        }
        void copy_SmartVault(const SmartVault& s){
            this->max_size = s.max_size;
            for (int i = 0; i < max_size; i++){
                pw[i] = s.pw[i];
            }
            this->cs = s.cs;
        }

        ~SmartVault() {free(pw);};
    protected:
        /// 외부에서는 접근 불가능
        int max_size;
        int* pw;
        CurrentStatus cs; 
};


int main(){
    SmartVault s(3);
    s.setSecret(5, 0000);
    s.setSecret(0, 0000).setSecret(1, 1111).setSecret(2, 2222);
    s.printPW();
    SmartVault b(3);
    b.copy_SmartVault(s);
    b.printPW();
}
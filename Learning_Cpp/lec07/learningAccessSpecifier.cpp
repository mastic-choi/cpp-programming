#include<iostream>
using namespace std;

class BankAccount{
    public:
    //외부 접근 가능
    void deposit(int amount){
        //외부에서 private값에 직접 접근 불가능하기 때문에 public 함수로 접근
        if(amount > 0){
            balance += amount;
        }    
    }
    int get_balance() const {
        return balance;}

        private:
        //외부에서 "직접" 접근 불가
        int balance = 0;

};

void call_my_account(const BankAccount& a){
    // get_balance객체를 const로 호출하고 싶으면 
    // int get_balance() const {}식으로 호출한다.
    int b = a.get_balance();
    cout << "my balance is " <<b << endl;
}

int main(void){
    BankAccount bcc;
    bcc.deposit(1000);
    //public 함수를 통해 private 함수 접근
    call_my_account(bcc);

    return 0;
}

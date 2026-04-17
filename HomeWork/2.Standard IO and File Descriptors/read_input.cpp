#include<iostream>
#include<string>


int main(void){
    std::string line;
    std::cout<<"Reading from STDIN. . ."<<std::endl;
    while(std::getline(std::cin, line)){
        std::cout << "Input : " << line << std::endl;
    }
}
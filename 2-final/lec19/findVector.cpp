#include<iostream>
#include<algorithm>
#include<vector>

int main(void){
    std::vector<int> v= {10, 20, 30, 40, 50};
    auto it = std::find(v.begin(), v.end(), 30); //end() 자체가 null이다 null은 vector에서 없다
    if(it != v.end()){
        // 만약에 find하지 못하면 그 iteractive 값이 end에 가있다, end가 아닌 다른 값에 있다는것은 목표값을 찾았다는뜻이다
        std::cout<< *it << std::endl;
    }
    else{
        std::cout<< "cannot find it !" << std::endl;
    }
    auto it = std::find(v.begin(), v.end(), 60);
}
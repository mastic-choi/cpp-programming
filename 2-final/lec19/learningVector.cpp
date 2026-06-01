#include<iostream>
#include<vector>
#include<algorithm>


int main(void){
    std::vector<int> v;
    v.resize(100);
    //이러면 push_pack 안쓰고 가능하다(v[1] = 1 식으로 입력 가능)
    //v는 {0, 0, 0, 0, 0}이 됨 (size: 5)
    v.reserve(100);
    // capacity: 5, size: 0
    // v[1] = 1 식으로 접근 불가(size는 0이기 때문이다)
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(7);
    v.push_back(2);
    v.push_back(99);
    v.push_back(45);
    v.push_back(55);
    
    v[3] = -2;
    for(int n : v){
        std::cout << n << ' ';
    }
    std::cout<<"\n";
    std::sort(v.begin(), v.end());
    for(int n : v){
        std::cout << n << ' ';
    }


    std::vector<float> my_v;
    std::vector<float>::iterator it;
    std::vector<float>::const_iterator cit; // 안바꿀거니깐 const_interator cit, cbegin

    for(cit = my_v.cbegin(); cit != my_v.cend(); ++it){
        std::cout<< *it << ' ';
    }
    std::cout<< '\n';

    return 0;
}
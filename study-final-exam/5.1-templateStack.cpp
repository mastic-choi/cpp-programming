#include<vector>
#include<stdexcept>

template<typename T>
class Stack{
    std::vector<t> data;
public:
    void push(const T& v)  {data.push_back(v); }
    void pop(){
        if (empty()) throw std::runtime_error("empty ");
        data.pop_back();
    }
    T top() const{
        if (empty()) throw std::runtime_error("empty ");
        return data.back();
    }


    bool empty() const {return data.empty(); }
    int size() const {return (int)data.size(); }
};
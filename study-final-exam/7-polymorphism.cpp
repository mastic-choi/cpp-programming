#include<iostream>
class Animal {
public:
    virtual void speak() const {printf("...\n");}
    virtual ~Animal();
};

class Dog: public Animal{
public:
    void speak() const override {printf("멍멍!\n");}
};

class Cat: public Animal{
public:
    void speak() const override {printf("야용!\n");}
};

int main(void){    
    Animal* p = new Dog();
    p -> speak();
    delete p;
}
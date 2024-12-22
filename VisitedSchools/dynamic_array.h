//
// Created by lazab on 3/31/2024.
//

#ifndef SCHOOL_TEST1_DYNAMIC_ARRAY_H
#define SCHOOL_TEST1_DYNAMIC_ARRAY_H
#include <iostream>
#include "domain.h"
using  namespace std;

template <typename TElem>
class dynamic_array {
private:
    int cap{};
    int size{};
    TElem * elements;

    void resize();

public:
    explicit dynamic_array(int cap=10);
    void remove_vector(int index);
    TElem * get_vector();
    dynamic_array<TElem>& operator=(const dynamic_array<TElem> &other);
    int get_size();
    void add_vector(TElem element);
};

template <typename TElem>
dynamic_array<TElem>::dynamic_array(int cap){
    this->cap=cap;
    this->size=0;
    this->elements=new TElem[this->cap];
}

template <typename TElem>
void dynamic_array<TElem>::resize(){
    this->cap=this->cap*2;
    auto *array=new TElem[this->cap];
    for(int i=0;i<this->size;i++)
        array[i]=this->elements[i];
    delete[] this->elements;
    this->elements=array;
}

template <typename TElem>
void dynamic_array<TElem>::remove_vector(int index){
    for(int i=index;i<this->size-1;i++)
        this->elements[i]=this->elements[i+1];
    this->size--;
}

template <typename TElem>
TElem * dynamic_array<TElem>::get_vector(){
    return this->elements;
}

template <typename TElem>
dynamic_array<TElem>& dynamic_array<TElem>::operator=(const dynamic_array<TElem> &other){
    delete[] this->elements;
    this->cap=other.cap;
    this->size=other.size;
    this->elements=new TElem[this->cap];
    for(int i=0;i< this->size;i++)
        this->elements[i]=other[i];
    return *this;
}

template <typename TElem>
int dynamic_array<TElem>::get_size(){
    return this->size;
}

template <typename TElem>
void dynamic_array<TElem>::add_vector(TElem element){
    if(this->cap==this->size){
        resize();
    }
    this->elements[this->size++]=element;
}


#endif //SCHOOL_TEST1_DYNAMIC_ARRAY_H

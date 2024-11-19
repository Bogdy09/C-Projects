//
// Created by lazab on 3/22/2024.
//

#ifndef OOP_A4_5_BOGDY09_DYNAMICVECTOR_H
#define OOP_A4_5_BOGDY09_DYNAMICVECTOR_H

#include <vector>
#include "domain.h"
/*
template <typename TElem>
class Dynamic_vector {
private:
    int size{};
    int cap{};
    int size1{};
    int cap1{};
    TElem *elements;
    TElem *elements1;

    void resize();
public:

    explicit Dynamic_vector(int cap=10);
    Dynamic_vector& operator=(const Dynamic_vector& arr);
    ~Dynamic_vector();
    void add_vector(const TElem &elem);
    void delete_vector(int index);
    void update_vector(int index, TElem &elem);
    TElem * get_vector();
    int get_size();
    int get_cap();
    void resize1();
    void add_vector1(const TElem &elem);
    int get_size1();
    TElem * get_vector1();
    void delete_vector1(int index);
};

template <typename TElem>
void Dynamic_vector<TElem>::resize(){
    this->cap=this->cap*2;
    TElem *vector=new TElem[this->cap];
    for(int i=0;i<this->size;i++)
        vector[i]=this->elements[i];
    delete[] this->elements;
    this->elements=vector;
}

template <typename TElem>
void Dynamic_vector<TElem>::resize1(){
    this->cap1=this->cap*2;
    TElem *vector=new TElem[this->cap];
    for(int i=0;i<this->size1;i++)
        vector[i]=this->elements1[i];
    delete[] this->elements1;
    this->elements1=vector;
}

template <typename TElem>
Dynamic_vector<TElem>::Dynamic_vector(int cap){
    this->cap=cap;
    this->size=0;
    this->cap1=cap;
    this->size1=0;
    this->elements=new TElem[cap];
    this->elements1=new TElem[cap];
}


template <typename TElem>
Dynamic_vector<TElem>& Dynamic_vector<TElem>::operator=(const Dynamic_vector& arr)
{
    delete[] elements;
    this->cap = arr.cap;
    this->size = arr.size;
    this->elements = new TElem[this->cap];
    for (int i = 0; i < arr.size; i++)
        this->elements[i] = arr.elements[i];
    return *this;
}

template <typename TElem>
Dynamic_vector<TElem>::~Dynamic_vector() {
    delete[] this->elements;
    delete[] this->elements1;
}

template <typename TElem>
void Dynamic_vector<TElem>::add_vector(const TElem &elem){
    if(this->size==this->cap)
        this->resize();
    this->elements[this->size++]=elem;
}

template <typename TElem>
void Dynamic_vector<TElem>::add_vector1(const TElem &elem){
    if(this->size1==this->cap1)
        this->resize1();
    this->elements1[this->size1++]=elem;
}

template <typename TElem>
void Dynamic_vector<TElem>::delete_vector(int index){
    for(int i=index;i<this->size-1;i++)
        this->elements[i]=this->elements[i+1];
    this->size--;
}

template <typename TElem>
void Dynamic_vector<TElem>::delete_vector1(int index){
    for(int i=index;i<this->size1-1;i++)
        this->elements1[i]=this->elements1[i+1];
    this->size1--;
}

template <typename TElem>
void Dynamic_vector<TElem>::update_vector(int index, TElem &elem) {
    this->elements[index]=elem;
}

template <typename TElem>
TElem * Dynamic_vector<TElem>::get_vector(){
    return this->elements;
}

template <typename TElem>
TElem * Dynamic_vector<TElem>::get_vector1(){
    return this->elements1;
}

template <typename TElem>
int Dynamic_vector<TElem>::get_size(){
    return this->size;
}

template <typename TElem>
int Dynamic_vector<TElem>::get_size1(){
    return this->size1;
}
template <typename TElem>
int Dynamic_vector<TElem>::get_cap() {
    return this->cap;
}


template <typename TElem>
class Dynamic_vector {
private:
    std::vector<TElem> *elements;
    std::vector<TElem> *elements1;
public:

    explicit Dynamic_vector(int cap=10)=default;
    Dynamic_vector& operator=(const Dynamic_vector& arr) {
        elements = arr.elements;
        elements1 = arr.elements1;
        return *this;
    }

    void add_vector(const TElem &elem){
        elements->push_back(elem);
    }

    void add_vector1(const TElem &elem){
        elements1->push_back(elem);
    }

    void delete_vector(int index){
        elements->erase(elements->begin()+index);
    }

    void delete_vector1(int index){
        elements1->erase(elements1->begin()+index);
    }

    void update_vector(int index, TElem &elem) {
        this->elements[index]=elem;
    }

    std::vector<TElem>& get_vector(){
        return elements;
    }

    std::vector<TElem>& get_vector1(){
        return elements1;
    }

    int get_size(){
        return elements->size();
    }

    int get_size1(){
        return elements1->size();
    }


};

*/





#endif //OOP_A4_5_BOGDY09_DYNAMICVECTOR_H

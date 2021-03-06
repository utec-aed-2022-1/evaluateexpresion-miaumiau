#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "forward.h"

template <typename T>
class StackList : public ForwardList<T> {
public:
    StackList();
    T top();
    bool empty();
    void push(T data);
    T pop();
    ~StackList(){};
};

template <class T>
StackList<T>::StackList() {
}

template <class T>
T StackList<T>::top(){
    return this->front();
}

template <class T>
bool StackList<T>::empty(){
    return this->is_empty();
}

template <class T>
void StackList<T>::push(T data){
    this->push_front(data);
}

template <class T>
T StackList<T>::pop(){
    return this->pop_front();
}

#endif
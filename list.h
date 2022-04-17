#ifndef LIST_H
#define LIST_H

#include "node.h"

// TODO: Implement all methods
template <typename T>
class List {
    private: 
    Node<T>* head;
    Node<T>* tail;
    int nodes;
    
    public:
        List() : head(nullptr), tail(nullptr), nodes(0) {};
        virtual ~List(){};

    protected:
        virtual T front() = 0;
        virtual T back() = 0;
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual T pop_front() = 0;
        virtual T pop_back() = 0;
        virtual T insert(T, int) = 0;
        virtual void remove(int) = 0;
        virtual T& operator[](int) = 0; //debe ser declarado en cada clase hija
        virtual bool is_empty() = 0;
        virtual int size() = 0;
        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual bool is_sorted() = 0;
        virtual void reverse() = 0;
        virtual std::string name() = 0;
};

template <typename T>
void swap(Node<T>* node01, Node<T>* node02){
    T temp = node01->data;
    node01->data = node02->data;
    node02->data = temp;
}

#endif
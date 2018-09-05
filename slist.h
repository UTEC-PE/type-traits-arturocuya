#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {     
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++() {
            this->current = this->current->next;
            return *this;
        };
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
            pointer = head;
            while (*pointer != nullptr) {
                if (*pointer->data == search) return true;
                *pointer = *pointer->next;
            }
            return false;
        }
             
        bool insert(T data) {
            if (!find(data, head)) {
                
            }
        }
             
        bool remove(T item) {
            // TODO
        }  
             
        iterator begin() {
            return iterator(head);
        }
             
        iterator end() {
            return iterator(nullptr);
        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif
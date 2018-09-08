#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"
using namespace std;
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
            while(*pointer) {
                if ( cmp(search , (*pointer)->data )) {
                    return search == (*pointer)->data;
                } else {
                    pointer = &((*pointer)->next);
                }
            }
            return false;return true;
        }
             
        bool insert(T data) {
            Node<T>* newNode = new Node<T>(data);
            if(head) {
                Node<T>** pointer = &head;
                if (!find(data, pointer)) {
                    newNode->next = *pointer;
                    *pointer = newNode;
                    return true;
                }
                return false;
            } else {
                head = newNode;
                return true;
            }
        }
             
        bool remove(T item) {
            Node<T>** pointer = &head;
            if ( find(item, pointer) ) {
                cout << *pointer << endl;
                Node<T>* tmp = *pointer;
                *pointer = (*pointer)->next;
                delete tmp;
                return true;
            }
            return false;
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
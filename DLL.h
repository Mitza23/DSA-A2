//
// Created by mitza on 31-Mar-21.
//

#ifndef A2_DLL_H
#define A2_DLL_H

#include <exception>
#include "DLLNode.h"

template <class elem>
class DLL {
private:
    DLLNode<elem>* head;
    DLLNode<elem>* tail;
public:
    DLL():head(nullptr), tail(nullptr){}

    void insertLast(elem info){
        DLLNode<elem>* node = new DLLNode<elem>(info, nullptr, tail);
        if(head == nullptr){
            head = node;
            tail = node;
        }
        else {
            tail->setNext(node);
            tail = node;
        }
    }

    void insertFirst(elem info){
        DLLNode<elem>* node = new DLLNode<elem>(info, head, nullptr);
        head->setPrev(node);
        head = node;
    }

    void insertPosition(elem info, int position){
        if(position < 1)
            throw exception();
        if(position == 1)
            insertFirst(info);

        DLLNode<elem>* prev = head;
        DLLNode<elem>* next;
        int currentPos = 1;

        while(currentPos < position - 1 && prev != nullptr){
            prev = prev->getNext();
            currentPos++;
        }

        if(prev == nullptr)
            throw exception();

        else if(prev == tail)
            insertLast(info);

        next = prev->getNext();
        DLLNode<elem>* node = new DLLNode<elem>(info, next, prev);
        next->setPrev(node);
        prev->setNext(node);
    }

    void deleteByValue(elem info){
        if(head == tail && head == nullptr)
            throw exception();
        DLLNode<elem>* current = head;
        while(current != nullptr && current->getInfo() != info){
            current = current->getNext();
        }

        if(current == nullptr)
            throw exception();
        if(head == tail && current == head) {
            head = tail = nullptr;
            return;
        }
        if(current == head) {
            head = head->getNext();
            return;
        }
        if(current == tail){
            tail = tail->getPrev();
            return;
        }
        DLLNode<elem>* prev = current->getPrev();
        DLLNode<elem>* next = current->getNext();
        prev->setNext(next);
        next->setPrev(prev);
        ///---------------
        ///delete current;
        ///---------------
    }

    DLLNode<elem>* findElement(elem info){
        DLLNode<elem>* current = head;
        while(current != nullptr && current->getInfo() !=  info)
            current = current->getNext();
        return current;
    }
};


#endif //A2_DLL_H

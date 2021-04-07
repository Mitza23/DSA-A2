//
// Created by mitza on 31-Mar-21.
//

#ifndef A2_DLLNode<elem>_H
#define A2_DLLNode<elem>_H


#include <utility>

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;

template <class elem>
class DLLNode {
private:
    elem info;
    DLLNode<elem>* next;
    DLLNode<elem>* prev;

public:
    DLLNode();

    DLLNode(elem info, DLLNode<elem> *next, DLLNode<elem> *prev);

    virtual ~DLLNode();

    const elem &getInfo() const;

    void setInfo(const elem &info);

    DLLNode<elem> *getNext() const;

    void setNext(DLLNode<elem> *next);

    DLLNode<elem> *getPrev() const;

    void setPrev(DLLNode<elem> *prev);
};

template <class elem>
const elem &DLLNode<elem>::getInfo() const {
    return info;
}

template <class elem>
void DLLNode<elem>::setInfo(const elem &info) {
    DLLNode<elem>::info = info;
}

template <class elem>
DLLNode<elem> *DLLNode<elem>::getNext() const {
    return next;
}

template <class elem>
void DLLNode<elem>::setNext(DLLNode<elem> *next) {
    DLLNode<elem>::next = next;
}

template <class elem>
DLLNode<elem> *DLLNode<elem>::getPrev() const {
    return prev;
}

template <class elem>
void DLLNode<elem>::setPrev(DLLNode<elem> *prev) {
    DLLNode<elem>::prev = prev;
}

template<class elem>
DLLNode<elem>::DLLNode() {
    next = nullptr;
    prev = nullptr;
}


template<class elem>
DLLNode<elem>::DLLNode(elem info, DLLNode<elem> *next, DLLNode<elem> *prev):info(info), next(next), prev(prev) {}

template<class elem>
DLLNode<elem>::~DLLNode() {
    delete this;
}

#endif //A2_DLLNode<elem>_H

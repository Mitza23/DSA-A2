#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

///Theta(1)
SortedMultiMap::SortedMultiMap(Relation r) {
	//TODO - Implementation
	nrElements = 0;
    head = nullptr; ///{<key, {info, head, tail}>, next, prev}
    tail = nullptr;
	relation = r;
}

///O(n)
void SortedMultiMap::add(TKey c, TValue v) {
	//TODO - Implementation
	if(nrElements == 0){
        auto newValue = new ValueNode{v, nullptr, nullptr};
        auto dll = pair<ValueNode*, ValueNode*>(newValue, newValue);
        auto info = pair<TKey, pair<ValueNode*, ValueNode*> >(c, dll);
        auto newNode = new KeyNode{info , nullptr, nullptr};
        head = newNode;
        tail = newNode;
        nrElements++;
        return;
	}
	else {
        nrElements++;
        auto current = head;
        auto prevKey =current->prev;
        while (current != nullptr && relation(current->info.first, c)) {

            if (current->info.first == c) {
                auto valueNode = current->info.second.first;
                auto prevValue = valueNode->prev;
                while (valueNode != nullptr && relation(valueNode->info, v)) {
                    prevValue = valueNode;
                    valueNode = valueNode->next;
                }
                if (valueNode != nullptr && !relation(valueNode->info, v)) {
                    auto newNode = new ValueNode{v, valueNode->prev, valueNode};
                    if (valueNode->prev != nullptr) {
                        valueNode->prev->next = newNode;
                        valueNode->prev = newNode;
                    }
                    else{
                        current->info.second.first = newNode;
                        valueNode->prev = newNode;
                    }
                    return;
                } else {//valueNode = nullptr
                    auto newNode = new ValueNode{v, prevValue, nullptr};
                    prevValue->next = newNode;
                    current->info.second.second = newNode;
                    return;
                }
            }
            prevKey = current;
            current = current->next;
        }

        if (current != nullptr && !relation(current->info.first, c)) {
            auto newValue = new ValueNode{v, nullptr, nullptr};
            auto dll = pair<ValueNode *, ValueNode *>(newValue, newValue);
            auto info = pair<TKey, pair<ValueNode *, ValueNode *> >(c, dll);
            auto newNode = new KeyNode{info, current->prev, current};
            if (current->prev != nullptr) {
                current->prev->next = newNode;
                current->prev = newNode;
            }
            else{
                head = newNode;
                current->prev = newNode;
            }
        } else {
            auto newValue = new ValueNode{v, nullptr, nullptr};
            auto dll = pair<ValueNode *, ValueNode *>(newValue, newValue);
            auto info = pair<TKey, pair<ValueNode *, ValueNode *> >(c, dll);
            auto newNode = new KeyNode{info, prevKey, nullptr};
            prevKey->next = newNode;
            tail = newNode;
        }
    }
}

///O(n)
vector<TValue> SortedMultiMap::search(TKey c) const {
    //TODO - Implementation
    auto result = vector<TValue>();
    auto current = head;
    while (current != nullptr && current->info.first != c) {
        current = current->next;
    }
    if (current != nullptr && current->info.first == c) {
        auto node = current->info.second.first;
        while (node != nullptr) {
            result.push_back(node->info);
            node = node->next;
        }
    }
    return result;
}

///O(n)
bool SortedMultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
    auto current = head;
    while(current != nullptr && current->info.first != c){
        current = current->next;
    }
    if(current != nullptr && current->info.first == c) {
        auto valueNode = current->info.second.first;
        while (valueNode != nullptr && valueNode->info != v) {
            valueNode = valueNode->next;
        }
        if(valueNode != nullptr) {
            if (valueNode->info == v) {
                if (valueNode->prev != nullptr)
                    valueNode->prev->next = valueNode->next;

                if (valueNode->next != nullptr)
                    valueNode->next->prev = valueNode->prev;

                if (valueNode->next == nullptr)
                    current->info.second.second = valueNode->prev;

                if (valueNode->prev == nullptr)
                    current->info.second.first = valueNode->next;

                delete valueNode;
                nrElements--;
                if (current->info.second.first == nullptr) {
                    if (current->next != nullptr)
                        current->next->prev = current->prev;

                    if (current->prev != nullptr)
                        current->prev->next = current->next;

                    if (current->next == nullptr)
                        tail = current->prev;

                    if (current->prev == nullptr)
                        head = current->next;

                    delete current;
                }
                return true;
            }
        }
    }
    return false;
}


///Theta(1)
int SortedMultiMap::size() const {
	//TODO - Implementation
	return nrElements;
}

///Theta(1)
bool SortedMultiMap::isEmpty() const {
	//TODO - Implementation
	if(nrElements > 0)
	    return false;
    return true;
}

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap() {
	//TODO - Implementation
	auto keyNode = head;
	if(keyNode != nullptr) {
        auto nextKey = keyNode->next;
        while (keyNode != nullptr) {
            //cout << keyNode->info.first << ": ";
            auto valueNode = keyNode->info.second.first;
            auto nextValue = valueNode->next;
            while (valueNode != nullptr) {
                //cout << valueNode->info << " ";
                delete valueNode;
                valueNode = nextValue;
                if (valueNode != nullptr)
                    nextValue = valueNode->next;
            }
            delete keyNode;
            keyNode = nextKey;
            if (keyNode != nullptr)
                nextKey = keyNode->next;
        }
    }
	head = nullptr;
	tail = nullptr;
}

void SortedMultiMap::show() {
    auto current = head;
    if(current != nullptr) {
        auto nextKey = current->next;
        while (current != nullptr) {
            cout << current->info.first << ": ";
            auto valueNode = current->info.second.first;
            auto nextValue = valueNode->next;
            while (valueNode != nullptr) {
                cout << valueNode->info << " ";
                valueNode = nextValue;
                if (valueNode != nullptr)
                    nextValue = valueNode->next;
            }
            cout << endl;
            current = nextKey;
            if (current != nullptr)
                nextKey = current->next;
        }
    }
    cout << endl;
}

/// Complexity:
/// BC = Theta(1) - the key is the first one and has only one value associated
/// WC = Theta(n) - the key has all values associated to it
/// AC = O(n)
/// \param key
/// \return
vector<TValue> SortedMultiMap::removeKey(TKey key) {
    auto result = vector<TValue>();
    auto current = head;
    while(current != nullptr && current->info.first != key) {
        current = current->next;
    }
    if(current != nullptr && current->info.first == key) {
        auto valueNode = current->info.second.first;
        auto nextValue = valueNode->next;
        while(valueNode != nullptr){
            result.push_back(valueNode->info);

            if (valueNode->prev != nullptr)
                valueNode->prev->next = valueNode->next;

            if (valueNode->next != nullptr)
                valueNode->next->prev = valueNode->prev;

            if (valueNode->next == nullptr)
                current->info.second.second = valueNode->prev;

            if (valueNode->prev == nullptr)
                current->info.second.first = valueNode->next;

            delete valueNode;
            nrElements--;
            if (current->info.second.first == nullptr) {
                if (current->next != nullptr)
                    current->next->prev = current->prev;

                if (current->prev != nullptr)
                    current->prev->next = current->next;

                if (current->next == nullptr)
                    tail = current->prev;

                if (current->prev == nullptr)
                    head = current->next;

                delete current;
            }

            valueNode = nextValue;
            if(valueNode != nullptr)
                nextValue = valueNode->next;
        }
    }
//    for(auto e: result)
//        remove(key, e);

    return result;
}

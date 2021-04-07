#include "SMMIterator.h"
#include "SortedMultiMap.h"

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	//TODO - Implementation
	keyNode = d.head;
	if(keyNode != nullptr)
	    valueNode = keyNode->info.second.first;
	else
	    valueNode = nullptr;
}

void SMMIterator::first(){
	//TODO - Implementation
    keyNode = map.head;
    if(keyNode != nullptr)
        valueNode = keyNode->info.second.first;
    else
        valueNode = nullptr;
}

void SMMIterator::next(){
    if(keyNode == nullptr)
        throw exception();
	valueNode = valueNode->next;
	if(valueNode == nullptr){
	    keyNode = keyNode->next;
        if(keyNode != nullptr)
            valueNode = keyNode->info.second.first;
	}
}

bool SMMIterator::valid() const{
	//TODO - Implementation
	if(valueNode != nullptr && keyNode != nullptr)
	    return true;
    return false;
}

TElem SMMIterator::getCurrent() const{
	//TODO - Implementation
	if(valid()){
	    TElem p(keyNode->info.first, valueNode->info);
        return p;
	}
    throw exception();
}



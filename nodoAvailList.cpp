#include "nodoAvailList.h"

nodoAvailList::nodoAvailList() {}
nodoAvailList::nodoAvailList(int recordNumber, nodoAvailList* next){
    this->recordNumber = recordNumber;
    this->next = next;
}
nodoAvailList::~nodoAvailList(){}

void nodoAvailList::serializeToBytes(char* buffer) const{}

void nodoAvailList::deserializeFromBytes(const char* buffer){}


int nodoAvailList::getRecordNumber() const{
    return recordNumber;
}
nodoAvailList* nodoAvailList::getNext() const{
    return next;
}

void nodoAvailList::setRecordNumber(int recordNumber){
    this->recordNumber = recordNumber;
}
void nodoAvailList::setNext(nodoAvailList* next){
    this->next = next;
}

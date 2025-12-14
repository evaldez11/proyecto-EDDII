#include "availlist.h"
#include <QDebug>
nodoAvailList* availList::head = nullptr;
QFile* availList::file = nullptr;
int availList::RNN = 0;
availList::availList() {}
availList::availList(int rnn) {
    RNN = rnn;
}

void availList::setFile(QFile* fileHandle) {
    file = fileHandle;
}

void availList::rebuildAvailList(int headRNN) {
    clear();

    if (headRNN == -1){
        qDebug() << "La availList esta vacia";
        return;
    } // Empty list

    try {
        int currentRNN = headRNN;
        nodoAvailList* previous = nullptr;

        while (currentRNN != -1) {
            nodoAvailList* current = new nodoAvailList(currentRNN, nullptr);

            if (previous == nullptr)
                head = current;
            else
                previous->setNext(current);


            int offset = currentRNN * RNN;
            file->seek(offset);

            char buffer[sizeof(int)];
            file->read(buffer, sizeof(int));

            int nextRNN;
            memcpy(&nextRNN, buffer, sizeof(int));

            previous = current;
            currentRNN = nextRNN;
        }
    } catch (const exception& e) {
        qDebug() << "Error rebuilding avail list: " << e.what() << "\n";
    }
}

void availList::addAvailSlot(int recordNumber) {
    nodoAvailList* newNode = new nodoAvailList(recordNumber, nullptr);


    if (head == nullptr) {
        head = newNode;
    } else {

        nodoAvailList* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }

        current->setNext(newNode);


        int offset = current->getRecordNumber() * RNN;
        file->seek(offset);

        char buffer[sizeof(int)];
        memcpy(buffer, &recordNumber, sizeof(int));
        file->write(buffer, sizeof(int));
    }


    int offset = recordNumber * RNN;
    file->seek(offset);

    char buffer[sizeof(int)];
    int nextRNN = -1;
    memcpy(buffer, &nextRNN, sizeof(int));

    file->write(buffer, sizeof(int));
    file->flush();
}

int availList::retrieveSpace() {
    if (head == nullptr) return -1;


    int recordNumber = head->getRecordNumber();
    nodoAvailList* temp = head;
    head = head->getNext();
    delete temp;

    return recordNumber;
}

int availList::getHeadRNN() {
    if (head == nullptr) return -1;
    return head->getRecordNumber();
}
void availList::setHeadRNN(nodoAvailList* Head){
    head = Head;
}
nodoAvailList* availList::getHead() {
    return head;
}

void availList::clear() {

    nodoAvailList* current = head;
    while (current != nullptr) {
        nodoAvailList* temp = current;
        current = current->getNext();
        delete temp;
    }
    head = nullptr;
}

int availList::getRNN() {
    return RNN;
}

void availList::persistAvailList() {

    file->seek(0);
    int headRNN = getHeadRNN();
    file->write((char*)&headRNN, sizeof(int));


    nodoAvailList* current = head;
    while (current != nullptr) {
        int offset = current->getRecordNumber() * RNN;
        file->seek(offset);

        char buffer[sizeof(int)];

        int nextRNN = (current->getNext() != nullptr) ?
                          current->getNext()->getRecordNumber() : -1;
        memcpy(buffer, &nextRNN, sizeof(int));

        file->write(buffer, sizeof(int));

        current = current->getNext();
    }

    file->flush();
}
void availList::setRNN(int rnn){
    RNN = rnn;
}

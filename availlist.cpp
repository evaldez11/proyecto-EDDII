#include "availlist.h"
#include <QDebug>
nodoAvailList* availList::head = nullptr;
fstream* availList::file = nullptr;
int availList::RNN = 0;
availList::availList() {}
availList::availList(int rnn) {
    RNN = rnn;
}

void availList::setFile(fstream* fileHandle) {
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

        // Traverse linked list from file, rebuilding in-memory structure
        while (currentRNN != -1) {
            nodoAvailList* current = new nodoAvailList(currentRNN, nullptr);

            if (previous == nullptr)
                head = current;
            else
                previous->setNext(current);

            // Read next pointer from file at this record's position
            int offset = currentRNN * RNN;
            file->seekg(offset, ios::beg);

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

    // If list is empty, new node becomes head
    if (head == nullptr) {
        head = newNode;
    } else {
        // Find last node and append new node
        nodoAvailList* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }

        current->setNext(newNode);

        // Update previous last node's next pointer in file
        int offset = current->getRecordNumber() * RNN;
        file->seekp(offset, ios::beg);

        char buffer[sizeof(int)];
        memcpy(buffer, &recordNumber, sizeof(int));
        file->write(buffer, sizeof(int));
    }

    // Write new node to file with next = -1 (marks end of list)
    int offset = recordNumber * RNN;
    file->seekp(offset, ios::beg);

    char buffer[sizeof(int)];
    int nextRNN = -1;
    memcpy(buffer, &nextRNN, sizeof(int));

    file->write(buffer, sizeof(int));
    file->flush();
}

int availList::retrieveSpace() {
    if (head == nullptr) return -1; // No available space

    // Remove and return head node's record number
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

nodoAvailList* availList::getHead() {
    return head;
}

void availList::clear() {
    // Deallocate all nodes in the list
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
    // Write head RNN to metadata (first 4 bytes of file)
    file->seekp(0, ios::beg);
    int headRNN = getHeadRNN();
    file->write((char*)&headRNN, sizeof(int));

    // Write all nodes' next pointers to their file positions
    nodoAvailList* current = head;
    while (current != nullptr) {
        int offset = current->getRecordNumber() * RNN;
        file->seekp(offset, ios::beg);

        char buffer[sizeof(int)];
        // Write next node's RNN or -1 if this is the last node
        int nextRNN = (current->getNext() != nullptr) ?
                          current->getNext()->getRecordNumber() : -1;
        memcpy(buffer, &nextRNN, sizeof(int));

        file->write(buffer, sizeof(int));

        current = current->getNext();
    }

    file->flush();
}

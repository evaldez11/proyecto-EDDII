#ifndef AVAILLIST_H
#define AVAILLIST_H
#include "nodoAvailList.h"
#include <fstream>


using namespace std;
class availList{
private:
    static nodoAvailList* head;
    static fstream* file;
    static int RNN;
public:
    availList();
    availList(int rnn);

    static void setFile(fstream* fileHandle);

    static void rebuildAvailList(int headRNN);

    static void addAvailSlot(int recordNumber);

    static int retrieveSpace();

    static int getHeadRNN();

    static nodoAvailList* getHead();

    static void clear();

    static int getRNN();

    static void persistAvailList();
};

#endif // AVAILLIST_H

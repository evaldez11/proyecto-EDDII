#ifndef AVAILLIST_H
#define AVAILLIST_H
#include <QFile>
#include "nodoAvailList.h"
#include <fstream>


using namespace std;
class availList{
private:
    static nodoAvailList* head;
    static QFile* file;
    static int RNN;
public:
    availList();
    availList(int rnn);

    static void setFile(QFile* fileHandle);

    static void rebuildAvailList(int headRNN);

    static void addAvailSlot(int recordNumber);

    static int retrieveSpace();

    static int getHeadRNN();

    static void setHeadRNN(nodoAvailList* head);

    static nodoAvailList* getHead();

    static void clear();

    static int getRNN();

    static void persistAvailList();
    void setRNN(int rnn);
};

#endif // AVAILLIST_H

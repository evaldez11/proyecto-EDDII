#ifndef NODOAVAILLIST_H
#define NODOAVAILLIST_H
#include <fstream>
using namespace std;
class nodoAvailList
{
private:
    int recordNumber;
    nodoAvailList* next;
public:
    nodoAvailList();
    nodoAvailList(int recordNumber, nodoAvailList* next = nullptr);
    ~nodoAvailList();

    void serializeToBytes(char* buffer) const;

    static void deserializeFromBytes(const char* buffer);

    // Getters
    int getRecordNumber() const;
    nodoAvailList* getNext() const;

    // Setters
    void setRecordNumber(int recordNumber);
    void setNext(nodoAvailList* next);
};

#endif // NODOAVAILLIST_H

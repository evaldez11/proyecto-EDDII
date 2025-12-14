#ifndef BTREENODE_H
#define BTREENODE_H
#include <vector>
#include "key.h"
class BTreeNode
{
public:
    vector<Key> keys;
    vector<BTreeNode*> children;
    int t;
    bool leaf;

    BTreeNode(int _t, bool _leaf);

    void insertNonFull(Key k);        // Insertar en un nodo no lleno
    void splitChild(int i, BTreeNode* y); // Dividir hijo
    void traverse();                  // Imprimir claves
    int search(long long k);

    void remove(Key k);
    Key getPredecessor(int idx);
    Key getSuccessor(int idx);
    void merge(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);


};

#endif // BTREENODE_H

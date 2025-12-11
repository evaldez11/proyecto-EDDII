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
    int search(int k);

};

#endif // BTREENODE_H

#ifndef BTREE_H
#define BTREE_H

#include "BTreeNode.h"
class BTree
{
private:
    BTreeNode* root;
    int t;  // Grado mínimo (cada nodo puede tener entre t-1 y 2t-1 claves)

public:
    BTree(int _t);

    void traverse() {
        if (root != nullptr)
            root->traverse();
    }

    BTreeNode* search(BTreeNode* nodo,int k);

    void insert(Key k);
    BTreeNode* getRoot();
};

#endif // BTREE_H

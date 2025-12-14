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

    BTreeNode* search(BTreeNode* nodo,long long k);

    void insert(Key k);
    void remove(Key k);
    BTreeNode* getRoot();

    void guardarNodo(ofstream& archivo, BTreeNode* nodo) ;
    BTreeNode* leerNodo(ifstream& archivo);
    void guardarArbol(const string& nombreArchivo);

    void leerArbol(const string& nombreArchivo);
};

#endif // BTREE_H

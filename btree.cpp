#include "btree.h"
#include <fstream>
#include <iostream>


BTree::BTree(int _t) {
    root = nullptr;
    t = _t;
}

void BTree::insert(Key k) {
    if (!root) {
        root = new BTreeNode(t, true);
        root->keys.push_back(k);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            BTreeNode* newParent = new BTreeNode(t, false);
            newParent->children.push_back(root);
            newParent->splitChild(0, root);

            int i = 0;
            if (newParent->keys[0].getllave() < k.getllave())
                i++;
            newParent->children[i]->insertNonFull(k);
            root = newParent;
        } else {
            root->insertNonFull(k);
        }
    }
}
BTreeNode* BTree::search(BTreeNode* nodo, int valorBuscado){
    if (!nodo) return nullptr;

    int i = 0;
    while (i < nodo->keys.size() && valorBuscado > nodo->keys[i].getllave()) {
        i++;
    }

    if (i < nodo->keys.size() && valorBuscado == nodo->keys[i].getllave()) {
        return nodo;
    }

    if (nodo->leaf) {
        return nullptr;
    }

    return search(nodo->children[i], valorBuscado);
}

BTreeNode* BTree::getRoot(){
    return root;
}

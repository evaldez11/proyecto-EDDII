#include "BTreeNode.h"
#include <qdebug.h>
#include <qlogging.h>

BTreeNode::BTreeNode(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;
}

// Recorrer el nodo y sus hijos
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!leaf)
            children[i]->traverse();
        qDebug() << " " << keys[i].getllave();
    }
    if (!leaf)
        children[i]->traverse();
}

// Buscar clave en el nodo
int BTreeNode::search(int k) {
    for (int i = 0; i < keys.size(); ++i) {
        if (keys[i].getllave() == k)
            return i; // encontrada
    }
    return -1; // no encontrada
}

// Insertar clave en nodo no lleno
void BTreeNode::insertNonFull(Key k) {
    int i = keys.size() - 1;

    if (leaf) {
        keys.push_back(Key());
        while (i >= 0 && keys[i].getllave() > k.getllave()) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
    } else {
        while (i >= 0 && keys[i].getllave() > k.getllave())
            i--;
        i++;

        if (children[i + 1]->keys.size() == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1].getllave() < k.getllave())
                i++;
        }
        children[i + 1]->insertNonFull(k);
    }
}

// Dividir hijo y mover la mediana al nodo padre
void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    for (int j = 0; j < t - 1; j++)
        z->keys.push_back(y->keys[j + t]);

    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->children.push_back(y->children[j + t]);
    }

    y->keys.resize(t - 1);
    y->children.resize(y->leaf ? 0 : t);

    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, y->keys[t - 1]);
}

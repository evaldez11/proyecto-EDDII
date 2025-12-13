#include "btree.h"
#include <cstdint>
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
BTreeNode* BTree::search(BTreeNode* nodo, long long valorBuscado){
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

void BTree::guardarNodo(ofstream& archivo, BTreeNode* nodo) {
    if (!nodo) return;

    // grado minimo
    archivo.write(reinterpret_cast<const char*>(&nodo->t), sizeof(int));

    // leaf como uint8_t
    uint8_t leaf = nodo->leaf ? 1 : 0;
    archivo.write(reinterpret_cast<const char*>(&leaf), sizeof(uint8_t));

    // claves
    int keyCount = nodo->keys.size();
    archivo.write(reinterpret_cast<const char*>(&keyCount), sizeof(int));

    for (Key& key : nodo->keys) {
        long long llave = key.getllave();
        archivo.write(reinterpret_cast<const char*>(&llave), sizeof(long long));

        size_t len = key.getResto().size();
        archivo.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
        archivo.write(key.getResto().data(), len);

        int pos = key.getPosicion();
        archivo.write(reinterpret_cast<const char*>(&pos), sizeof(int));
    }

    // hijos
    int childCount = nodo->children.size();
    archivo.write(reinterpret_cast<const char*>(&childCount), sizeof(int));

    for (BTreeNode* child : nodo->children) {
        guardarNodo(archivo, child);
    }
}


BTreeNode* BTree::leerNodo(ifstream& archivo) {
    int t;
    if (!archivo.read(reinterpret_cast<char*>(&t), sizeof(int)))
        return nullptr;

    uint8_t leafByte;
    archivo.read(reinterpret_cast<char*>(&leafByte), sizeof(uint8_t));
    bool leaf = leafByte != 0;

    BTreeNode* nodo = new BTreeNode(t, leaf);

    int keyCount;
    archivo.read(reinterpret_cast<char*>(&keyCount), sizeof(int));

    for (int i = 0; i < keyCount; ++i) {
        long long llave;
        archivo.read(reinterpret_cast<char*>(&llave), sizeof(long long));

        size_t len;
        archivo.read(reinterpret_cast<char*>(&len), sizeof(size_t));
        string resto(len, '\0');
        archivo.read(&resto[0], len);

        int pos;
        archivo.read(reinterpret_cast<char*>(&pos), sizeof(int));

        nodo->keys.emplace_back(llave, resto, pos);
    }

    int childCount;
    archivo.read(reinterpret_cast<char*>(&childCount), sizeof(int));

    for (int i = 0; i < childCount; ++i) {
        BTreeNode* hijo = leerNodo(archivo);
        if (hijo) {
            nodo->children.push_back(hijo);
        }
    }

    return nodo;
}


void BTree::guardarArbol(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::binary);
    if (!archivo) return;

    guardarNodo(archivo, root);
    archivo.close();
}

void BTree::leerArbol(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) return;

    delete root;
    root = leerNodo(archivo);
    archivo.close();
}


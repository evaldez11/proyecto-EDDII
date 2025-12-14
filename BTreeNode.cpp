#include "BTreeNode.h"
#include <qdebug.h>
#include <qlogging.h>

BTreeNode::BTreeNode(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!leaf && i < children.size() && children[i])
            children[i]->traverse();

        qDebug() << keys[i].getllave();
    }

    if (!leaf && i < children.size() && children[i])
        children[i]->traverse();
}


int BTreeNode::search(long long k) {
    for (int i = 0; i < keys.size(); ++i) {
        if (keys[i].getllave() == k)
            return i;
    }
    return -1;
}

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

        if (children[i]->keys.size() == 2 * t - 1) {
            splitChild(i, children[i]);
            if (keys[i].getllave() < k.getllave())
                i++;
        }
        children[i]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    for (int j = 0; j < t - 1; j++)
        z->keys.push_back(y->keys[j + t]);

    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->children.push_back(y->children[j + t]);
    }

    Key median = y->keys[t - 1];

    y->keys.resize(t - 1);
    y->children.resize(y->leaf ? 0 : t);

    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, median);
}

void BTreeNode::remove(Key k) {
    int idx = search(k.getllave());


    if (idx < keys.size() && keys[idx].getllave() == k.getllave()) {
        if (leaf) {
            keys.erase(keys.begin() + idx);
        } else {
            if (children[idx]->keys.size() >= t) {
                Key pred = getPredecessor(idx);
                keys[idx] = pred;
                children[idx]->remove(pred);
            } else if (children[idx + 1]->keys.size() >= t) {
                Key succ = getSuccessor(idx);
                keys[idx] = succ;
                children[idx + 1]->remove(succ);
            } else {
                merge(idx);
                children[idx]->remove(k);
            }
        }
    } else {
        if (leaf) return; // no existe en el árbol

        bool atLastChild = (idx == keys.size());
        if (children[idx]->keys.size() < t)
            fill(idx);
        if (atLastChild && idx > keys.size())
            children[idx - 1]->remove(k);
        else
            children[idx]->remove(k);
    }
}

Key BTreeNode::getPredecessor(int idx) {
    BTreeNode* cur = children[idx];
    while (!cur->leaf)
        cur = cur->children.back();
    return cur->keys.back();
}


Key BTreeNode::getSuccessor(int idx) {
    BTreeNode* cur = children[idx + 1];
    while (!cur->leaf)
        cur = cur->children.front();
    return cur->keys.front();
}

void BTreeNode::merge(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];

    child->keys.push_back(keys[idx]);

    for (const Key& k : sibling->keys)
        child->keys.push_back(k);

    if (!child->leaf)
        for (BTreeNode* c : sibling->children)
            child->children.push_back(c);

    keys.erase(keys.begin() + idx);
    children.erase(children.begin() + idx + 1);
    delete sibling;
}

void BTreeNode::fill(int idx) {
    if (idx != 0 && children[idx - 1]->keys.size() >= t)
        borrowFromPrev(idx);
    else if (idx != keys.size() && children[idx + 1]->keys.size() >= t)
        borrowFromNext(idx);
    else {
        if (idx != keys.size())
            merge(idx);
        else
            merge(idx - 1);
    }
}

void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx - 1];

    child->keys.insert(child->keys.begin(), keys[idx - 1]);

    if (!child->leaf)
        child->children.insert(child->children.begin(), sibling->children.back());

    keys[idx - 1] = sibling->keys.back();
    sibling->keys.pop_back();
    if (!sibling->leaf)
        sibling->children.pop_back();
}

void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];

    child->keys.push_back(keys[idx]);

    if (!child->leaf)
        child->children.push_back(sibling->children.front());

    keys[idx] = sibling->keys.front();
    sibling->keys.erase(sibling->keys.begin());
    if (!sibling->leaf)
        sibling->children.erase(sibling->children.begin());
}


#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H
#include <iostream>

using namespace  std;

class Node {
private:
    int key;
    int height = 1;
public:
    Node* left = nullptr;
    Node* right = nullptr;
    Node();
    explicit Node(int _key) {
        key = _key;
    }
    int getval() const {
        return key;
    }
    pair<int, int> childheight() {
        int rheight = 0, lheight = 0;
        if (right != nullptr) rheight = right->height;
        if (left != nullptr) lheight = left->height;
        return {lheight, rheight};
    }
    int bfactor() {
        pair<int, int> chheight = childheight();
        return chheight.second - chheight.first;
    }
    void fixheight() {
        pair<int, int> chheight = childheight();
        height = max(chheight.first, chheight.second) + 1;
    }
    Node* rotateright() {
        Node* root = left;
        left = root->right;
        root->right = this;
        fixheight();
        root->fixheight();
        return root;
    }
    Node* rotateleft() {
        Node* root = right;
        right = root->left;
        root->left = this;
        fixheight();
        root->fixheight();
        return root;
    }
    Node* balance() {
        fixheight();
        if (bfactor() == 2) {
            if (right->bfactor() < 0) {
                right = right->rotateright();
            }
            return rotateleft();
        }
        if (bfactor() == -2) {
            if (left->bfactor() < 0) {
                left = left->rotateleft();
            }
            return rotateright();
        }
        return this;
    }
    Node* insert(int _key) {
        if (_key > key) {
            if (right == nullptr) {
                right = new Node(_key);
            } else {
                right = right->insert(_key);
            }
        }
        if (_key < key) {
            if (left == nullptr) {
                left = new Node(_key);
            }
            else {
                left = left->insert(_key);
            }
        }
        return balance();
    }
    Node* search(int _key) {
        if (key == _key) {
            return this;
        } else {
            if (_key > key) {
                if (right == nullptr) {
                    return nullptr;
                }
                return right->search(_key);
            }
            if (_key < key) {
                if (left == nullptr) {
                    return nullptr;
                }
                return left->search(_key);
            }
        }
    }
    Node* min() {
        if (this == nullptr) return nullptr;
        if (left == nullptr) return this;
        Node* pnode = this;
        while (pnode->left != nullptr) {
            pnode = pnode->left;
        }
        return pnode;
    }
    Node* remove_min() {
        if (left == nullptr) {
            Node* pnode = right;
            right = nullptr;
            return pnode;
        } else {
            left = left->remove_min();
            return balance();
        }
    }
    Node* remove(int _key) {
        if (_key > key) {
            if (right != nullptr)
                right = right->remove(_key);
        }
        else if (_key < key) {
            if (left != nullptr)
                left = left->remove(_key);
        } else {
            Node* l = left;
            Node* r = right;
            delete this;
            if (r == nullptr) {
                return l;
            }
            Node* m = r->min();
            m->right = r->remove_min();
            m->left = l;
            return m->balance();
        }
        return balance();
    }
    void print_tree() {
        if (left != nullptr) {
            left->print_tree();
        }
        for (int i = 0; i < height; ++i) {
            cout << "   ";
        }
        cout << key << endl;
        if (right != nullptr) {
            right->print_tree();
        }
    }
};

class AVLTree {
private:
    Node* root = nullptr;
public:
    void insert(int key) {
        if (root == nullptr) {
            root = new Node(key);
            return;
        }
        root = root->insert(key);
    }
    void print_tree() {
        if (root != nullptr)
            root->print_tree();
    }
    Node* search(int key) {
        if (root != nullptr)
        return root->search(key);
        return nullptr;
    }
    Node* min() {
        return root->min();
    }
    void remove_min() {
        if (root) {
            root = root->remove_min();
        }
    }
    void remove(int key) {
        if (root != nullptr)
            root = root->remove(key);
    }
};

#endif //AVLTREE_AVLTREE_H

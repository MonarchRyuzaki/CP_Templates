#include <bits/stdc++.h>
using namespace std;

class Node {
private:
    Node* children[2];
    int endsHereCount;
public:
    Node() {
        endsHereCount = 0;
        children[0] = children[1] = nullptr;
    }
    bool hasChild(int i) {
        return children[i] != nullptr;
    }
    void createChild(int i) {
        children[i] = new Node();
    }
    Node* getChild(int i) {
        return children[i];
    }
    void incrementEnd() {
        endsHereCount++;
    }
    void decrementEnd() {
        if (endsHereCount > 0) endsHereCount--;
    }
    bool isEnd() {
        return endsHereCount > 0;
    }
    bool canErase() {
        return !children[0] && !children[1] && endsHereCount == 0;
    }
    void eraseChild(int i) {
        delete children[i];
        children[i] = nullptr;
    }
};

class Trie {
private:
    Node* root;

    bool eraseRec(int num, int bitIndex, Node* node) {
        if (bitIndex < 0) {
            node->decrementEnd();
            return node->canErase();
        }
        int bit = (num >> bitIndex) & 1;
        if (node->hasChild(bit)) {
            bool canEraseChild = eraseRec(num, bitIndex - 1, node->getChild(bit));
            if (canEraseChild) {
                node->eraseChild(bit);
            }
        }
        return node->canErase();
    }

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* curr = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!curr->hasChild(bit)) {
                curr->createChild(bit);
            }
            curr = curr->getChild(bit);
        }
        curr->incrementEnd();
    }

    bool search(int num) {
        Node* curr = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!curr->hasChild(bit)) {
                return false;
            }
            curr = curr->getChild(bit);
        }
        return curr->isEnd();
    }

    void erase(int num) {
        if (!search(num)) return;
        eraseRec(num, 31, root);
    }

    bool startsWith(int num, int bitLength) {
        Node* curr = root;
        for (int i = 31; i >= 32 - bitLength; --i) {
            int bit = (num >> i) & 1;
            if (!curr->hasChild(bit)) {
                return false;
            }
            curr = curr->getChild(bit);
        }
        return true;
    }

    int getXOR(int val) {
        int xr = 0;
        Node* curr = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (curr->hasChild(1 - bit)) {
                xr |= (1 << i);
                curr = curr->getChild(1 - bit);
            } else {
                curr = curr->getChild(bit);
            }
        }
        return xr;
    }

    ~Trie() {
        delete root;
    }
};
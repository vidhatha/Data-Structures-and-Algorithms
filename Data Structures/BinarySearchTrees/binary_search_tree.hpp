#pragma once
#include <iostream>

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node();
    Node(int key);
};

class BinarySearchTree
{
    Node* root;

public:
    BinarySearchTree();

    void insert(int key);
    bool search(int key);
    void inorder_traversal();
    void preorder_traversal();
    void postorder_traversal();
    void erase(int key);
    int size();

    Node* getRoot();
    Node* successor(Node* node);
    Node* predecessor(Node* node);
    int heightOfTree();

private:
    Node* insert(Node* root, int key);
    Node* search(Node* root, int key);
    void inorder_traversal(Node* root);
    void preorder_traversal(Node* root);
    void postorder_traversal(Node* root);
    Node* erase(Node* root, int key);
    int size(Node* root);
    int heightOfTree(Node* root);

};

#include "LetsPlay.hpp"

using namespace std;

Node::Node()
{
    key = 0;
    left = NULL;
    right = NULL;
}

Node::Node(int value)
{
    key = value;
    left = NULL;
    right = NULL;
}

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

Node* BinarySearchTree::getRoot()
{
    return root;
}

Node* BinarySearchTree::insert(Node* root, int key)
{
    if (root == NULL)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

/**
 * @brief Search for a particular element in BST
 *
 * @param root
 * @param key
 * @return Node*
 */
Node* BinarySearchTree::search(Node* root, int key)
{
    if (root == NULL || key == root->key)
        return root;

    if (key < root->key)
        return search(root->left, key);
    
    return search(root->right, key);
}

/**
 * @brief Perform a in-order traversal of a BinarySearchTree.
 * @param root
 */
void BinarySearchTree::inorder_traversal(Node* root)
{
    if (root == NULL)
        return;

    inorder_traversal(root->left);
    cout << root->key << " ";
    inorder_traversal(root->right);
}

/**
 * @brief perform a pre-order traversal of a BinarySearchTree.
 * @param root 
*/
void BinarySearchTree::preorder_traversal(Node* root)
{
    if (root == NULL)
        return;

    cout << root->key << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

/**
 * @brief perform a post-order traversal of a BinarySearchTree.
 * @param root
*/
void BinarySearchTree::postorder_traversal(Node* root)
{
    if (root == NULL)
        return;

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->key << " ";
}

Node* BinarySearchTree::erase(Node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = erase(root->left, key);
    else if (key > root->key)
        root->right = erase(root->right, key);
    else
    {
        //node to be deleted has no children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        //node to be deleted has one child
        if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //node to be deleted has two children
        //1. get inorder successor
        Node* temp = successor(root);
        //update the node element with successor value
        root-> key = temp->key;
        //delete successor node
        erase(root->right, temp->key);
    }

    return root;

}

int BinarySearchTree::size(Node* root)
{
    if (root == NULL)
        return 0;

    return size(root->left) + 1 + size(root->right);
}

int BinarySearchTree::heightOfTree(Node* root)
{
    if (root == NULL)
        return 0;

    int heightOfLeftSubTree = heightOfTree(root->left);
    int heightOfRightSubTree = heightOfTree(root->right);

    if (heightOfLeftSubTree > heightOfRightSubTree)
        return heightOfLeftSubTree + 1;

    return heightOfRightSubTree + 1;
}

Node* BinarySearchTree::successor(Node* node)
{
    Node* node_successor = node;

    //get the right child
    node_successor = node_successor->right;

    //get the leftmost leaf of the right child
    while (node_successor->left != NULL)
        node_successor = node_successor->left;

    return node_successor;
}

Node* BinarySearchTree::predecessor(Node* node)
{
    Node* node_predecessor = node;

    //get the left child
    node_predecessor = node_predecessor->left;

    //get the rightmost leaf of the left child
    while (node_predecessor->right != NULL)
        node_predecessor = node_predecessor->right;

    return node_predecessor;
}

#pragma region Public APIs
void BinarySearchTree::insert(int key)
{
    root = insert(root, key);
}

bool BinarySearchTree::search(int key)
{
    Node* node = search(root, key);
    if (node == NULL)
        return false;

    return true;
}

void BinarySearchTree::inorder_traversal()
{
    inorder_traversal(root);
}
void BinarySearchTree::preorder_traversal()
{
    preorder_traversal(root);
}
void BinarySearchTree::postorder_traversal()
{
    postorder_traversal(root);
}
void BinarySearchTree::erase(int key)
{
    erase(root, key);
}
int BinarySearchTree::heightOfTree()
{
    return heightOfTree(root);
}

int BinarySearchTree::size()
{
    return size(root);
}
#pragma endregion PrivateMembers

int main()
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(90);
    bst.insert(40);
    bst.insert(80);
    bst.insert(10);
    bst.insert(60);

    cout << "InOrder Traversal: ";
    bst.inorder_traversal();
    cout << endl;

    cout << "PreOrder Traversal: ";
    bst.preorder_traversal();
    cout << endl;

    cout << "PostOrder Traversal: ";
    bst.postorder_traversal();
    cout << endl;

    //Check if element is present - positive case
    int elementToFind = 70;
    if (bst.search(elementToFind))
        cout << "Element " << elementToFind << "  found" << endl;
    else
        cout << "Element " << elementToFind << "  not found" << endl;

    //Check if element is present - negative case
    elementToFind = 71;
    bst.search(elementToFind);
    if (bst.search(elementToFind))
        cout << "Element " << elementToFind << "  found" << endl;
    else
        cout << "Element " << elementToFind << "  not found" << endl;

    cout << "Size of BST: " << bst.size() << endl;
    cout << "Height of BST: " << bst.heightOfTree() << endl;
    int elementToDelete = 70;
    bst.erase(elementToDelete);
    cout << "Element Deleted: " << elementToDelete << endl;
    cout << "InOrder Traversal: ";
    bst.inorder_traversal();
    cout << endl;

    return 0;
}

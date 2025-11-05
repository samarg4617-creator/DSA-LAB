#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}


Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}


Node* searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, Node* node) {

    if (node->right != nullptr)
        return findMin(node->right);

    Node* successor = nullptr;
    while (root != nullptr) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else break;
    }
    return successor;
}


Node* inorderPredecessor(Node* root, Node* node) {

    if (node->left != nullptr)
        return findMax(node->left);

    Node* predecessor = nullptr;
    while (root != nullptr) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else break;
    }
    return predecessor;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    int key = 40;
    cout << "\nSearching for " << key << " (Recursive): ";
    cout << (searchRecursive(root, key) ? "Found" : "Not Found");

    cout << "\nSearching for " << key << " (Iterative): ";
    cout << (searchIterative(root, key) ? "Found" : "Not Found");


    cout << "\n\nMaximum element: " << findMax(root)->data;


    cout << "\nMinimum element: " << findMin(root)->data;


    Node* node = searchRecursive(root, 60);
    Node* succ = inorderSuccessor(root, node);
    if (succ)
        cout << "\nInorder Successor of " << node->data << " is: " << succ->data;
    else
        cout << "\nInorder Successor of " << node->data << " does not exist.";


    Node* pred = inorderPredecessor(root, node);
    if (pred)
        cout << "\nInorder Predecessor of " << node->data << " is: " << pred->data;
    else
        cout << "\nInorder Predecessor of " << node->data << " does not exist.";

    cout << endl;
    return 0;
}
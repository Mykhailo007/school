#include <iostream>

using namespace std;

// define the structure for a node in the binary tree
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// function to insert a new node into the binary tree
Node* insertNode(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->value) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

int main() {
    // create an empty binary tree
    Node* root = nullptr;

    // insert nodes into the binary tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // print out the values of the binary tree
    cout << "Values in binary tree: ";
    cout << root->value << " ";
    cout << root->left->value << " ";
    cout << root->left->left->value << " ";
    cout << root->left->right->value << " ";
    cout << root->right->value << " ";
    cout << root->right->left->value << " ";
    cout << root->right->right->value << " ";
    cout << endl;

    return 0;
}

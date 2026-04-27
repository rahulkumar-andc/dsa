#include <iostream>
using namespace std;

class Node {
public:
    int data, height;
    Node* left;
    Node* right;
    Node(int val) : data(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int getBalance(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    void updateHeight(Node* n) {
        if (n)
            n->height = 1 + max(height(n->left), height(n->right));
    }

    // Right Rotation
    Node* rotateRight(Node* y) {
        Node* x  = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left  = T2;
        updateHeight(y);
        updateHeight(x);
        cout << "Right rotation at " << y->data << "\n";
        return x;
    }

    // Left Rotation
    Node* rotateLeft(Node* x) {
        Node* y  = x->right;
        Node* T2 = y->left;
        y->left  = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        cout << "Left rotation at " << x->data << "\n";
        return y;
    }

    // Insert helper
    Node* insert(Node* root, int x) {
        // Standard BST insert
        if (root == nullptr) return new Node(x);
        if (x < root->data)       root->left  = insert(root->left, x);
        else if (x > root->data)  root->right = insert(root->right, x);
        else { cout << "Element " << x << " already exists.\n"; return root; }

        updateHeight(root);
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && x < root->left->data)
            return rotateRight(root);

        // Right Right Case
        if (balance < -1 && x > root->right->data)
            return rotateLeft(root);

        // Left Right Case
        if (balance > 1 && x > root->left->data) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right Left Case
        if (balance < -1 && x < root->right->data) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    // Search helper
    Node* search(Node* root, int x) {
        if (root == nullptr) {
            cout << "Element " << x << " not found.\n";
            return nullptr;
        }
        if (root->data == x) {
            cout << "Element " << x << " found at address: " << root
                 << " (height=" << root->height << ")\n";
            return root;
        }
        if (x < root->data) return search(root->left, x);
        return search(root->right, x);
    }

    // Inorder traversal (sorted order)
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << "(h=" << root->height << ") ";
        inorder(root->right);
    }

public:
    Node* root;
    AVLTree() : root(nullptr) {}

    void insert(int x) {
        cout << "\nInserting " << x << "...\n";
        root = insert(root, x);
    }

    Node* search(int x) { return search(root, x); }

    void display() {
        cout << "Inorder (sorted): ";
        inorder(root);
        cout << "\n";
    }
};

int main() {
    AVLTree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);  // Triggers Left-Left rotation
    avl.insert(40);
    avl.insert(50);  // Triggers Left-Left rotation
    avl.insert(25);

    cout << "\n--- AVL Tree (Inorder) ---\n";
    avl.display();

    cout << "\n--- Search ---\n";
    avl.search(25);
    avl.search(99);

    return 0;
}

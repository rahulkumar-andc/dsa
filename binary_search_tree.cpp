#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Helper: find minimum node
    Node* minNode(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Helper insert
    Node* insert(Node* root, int x) {
        if (root == nullptr) return new Node(x);
        if (x < root->data)      root->left  = insert(root->left, x);
        else if (x > root->data) root->right = insert(root->right, x);
        else cout << "Element " << x << " already exists.\n";
        return root;
    }

    // Helper delete
    Node* deleteNode(Node* root, int x) {
        if (root == nullptr) { cout << "Element " << x << " not found.\n"; return nullptr; }
        if (x < root->data)
            root->left = deleteNode(root->left, x);
        else if (x > root->data)
            root->right = deleteNode(root->right, x);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                cout << "Deleted " << x << ".\n";
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                cout << "Deleted " << x << ".\n";
                delete root;
                return temp;
            }
            // Two children: replace with inorder successor
            Node* temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // Helper search
    Node* search(Node* root, int x) {
        if (root == nullptr) { cout << "Element " << x << " not found.\n"; return nullptr; }
        if (root->data == x) {
            cout << "Element " << x << " found at address: " << root << "\n";
            return root;
        }
        if (x < root->data) return search(root->left, x);
        return search(root->right, x);
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

public:
    BST() : root(nullptr) {}

    // i. Insert
    void insert(int x)      { root = insert(root, x); }
    // ii. Delete
    void deleteNode(int x)  { root = deleteNode(root, x); }
    // iii. Search
    Node* search(int x)     { return search(root, x); }

    // iv. Traversals
    void showPreorder()  { cout << "Preorder  : "; preorder(root);  cout << "\n"; }
    void showInorder()   { cout << "Inorder   : "; inorder(root);   cout << "\n"; }
    void showPostorder() { cout << "Postorder : "; postorder(root); cout << "\n"; }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "\n--- Traversals ---\n";
    tree.showPreorder();
    tree.showInorder();
    tree.showPostorder();

    cout << "\n--- Search ---\n";
    tree.search(40);
    tree.search(99);

    cout << "\n--- Delete ---\n";
    tree.deleteNode(30);
    tree.showInorder();

    tree.deleteNode(50);
    tree.showInorder();

    return 0;
}

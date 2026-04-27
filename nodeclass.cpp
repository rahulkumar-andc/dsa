#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    
};
int main() {
    Node* head = new Node(10);
    cout << "Node data: " << head->data << endl;
     return 0;
} 
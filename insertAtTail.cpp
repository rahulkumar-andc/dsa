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

void insertAtTail(Node*& head, int d) {
    Node* newNode = new Node(d);
    newNode->data = d;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}
int main() {
    Node* head = new Node(13);
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    printList(head);
    return 0;
} 
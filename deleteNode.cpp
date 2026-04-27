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

void insertAtHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->data = d;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->data = d;
    if (head == nullptr) {
        head = temp;
        return;
    }
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = temp;
}

void insertAtPosition(Node*& head, int position, int d) {
    if (position == 0) {
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        insertAtTail(head, d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->data = d;
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void deleteList(Node*& head) {
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}
int main() {
    Node* head = new Node(123);
    cout << "Node data: " << head->data << endl;
    insertAtHead(head, 35);
    printList(head);
    //deleteList(head);
    //printList(head);
    return 0;
} 
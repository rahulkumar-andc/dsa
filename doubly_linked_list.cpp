#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // i. Insert at beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        cout << "Inserted " << x << " at beginning.\n";
    }

    // ii. Insert at end
    void insertAtEnd(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << x << " at end.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << x << " at end.\n";
    }

    // iii. Remove from beginning
    void removeFromBeginning() {
        if (head == nullptr) { cout << "List is empty.\n"; return; }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        cout << "Removed " << temp->data << " from beginning.\n";
        delete temp;
    }

    // iv. Remove from end
    void removeFromEnd() {
        if (head == nullptr) { cout << "List is empty.\n"; return; }
        Node* temp = head;
        if (temp->next == nullptr) {
            cout << "Removed " << temp->data << " from end.\n";
            delete temp;
            head = nullptr;
            return;
        }
        while (temp->next != nullptr)
            temp = temp->next;
        temp->prev->next = nullptr;
        cout << "Removed " << temp->data << " from end.\n";
        delete temp;
    }

    // Display
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.display();

    list.removeFromBeginning();
    list.display();

    list.removeFromEnd();
    list.display();

    return 0;
}

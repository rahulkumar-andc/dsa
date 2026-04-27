#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // i. Insert at beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << x << " at beginning.\n";
    }

    // ii. Insert at ith position
    void insertAtPosition(int x, int pos) {
        Node* newNode = new Node(x);
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << x << " at position " << pos << ".\n";
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Position out of range.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << x << " at position " << pos << ".\n";
    }

    // iii. Remove from beginning
    void removeFromBeginning() {
        if (head == nullptr) { cout << "List is empty.\n"; return; }
        Node* temp = head;
        head = head->next;
        cout << "Removed " << temp->data << " from beginning.\n";
        delete temp;
    }

    // iv. Remove from ith position
    void removeFromPosition(int pos) {
        if (head == nullptr) { cout << "List is empty.\n"; return; }
        Node* temp = head;
        if (pos == 1) {
            head = head->next;
            cout << "Removed " << temp->data << " from position " << pos << ".\n";
            delete temp;
            return;
        }
        Node* prev = nullptr;
        for (int i = 1; i < pos && temp != nullptr; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) { cout << "Position out of range.\n"; return; }
        prev->next = temp->next;
        cout << "Removed " << temp->data << " from position " << pos << ".\n";
        delete temp;
    }

    // vi. Search and return pointer
    Node* search(int x) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == x) {
                cout << "Element " << x << " found at position " << pos
                     << ", address: " << temp << "\n";
                return temp;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element " << x << " not found.\n";
        return nullptr;
    }

    // Display
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.display();

    list.insertAtPosition(99, 2);
    list.display();

    list.removeFromBeginning();
    list.display();

    list.removeFromPosition(2);
    list.display();

    list.search(10);
    list.search(50);

    return 0;
}

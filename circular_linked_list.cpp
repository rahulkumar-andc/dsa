#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // i. Insert element x
    void insert(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
            cout << "Inserted " << x << ".\n";
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        cout << "Inserted " << x << ".\n";
    }

    // ii. Remove element x
    void removeElement(int x) {
        if (head == nullptr) { cout << "List is empty.\n"; return; }

        Node* curr = head;
        Node* prev = nullptr;

        Node* last = head;
        while (last->next != head) last = last->next;

        do {
            if (curr->data == x) {
                if (curr == head && curr->next == head) {
                    // Only one node
                    delete curr;
                    head = nullptr;
                } else if (curr == head) {
                    last->next = head->next;
                    head = head->next;
                    delete curr;
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
                cout << "Removed " << x << " from list.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Element " << x << " not found.\n";
    }

    // iii. Search and return pointer
    Node* search(int x) {
        if (head == nullptr) { cout << "List is empty.\n"; return nullptr; }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == x) {
                cout << "Element " << x << " found at position " << pos
                     << ", address: " << temp << "\n";
                return temp;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Element " << x << " not found.\n";
        return nullptr;
    }

    // Display
    void display() {
        if (head == nullptr) { cout << "List is empty.\n"; return; }
        Node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }

    ~CircularLinkedList() {
        if (!head) return;
        Node* curr = head->next;
        while (curr != head) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
    }
};

int main() {
    CircularLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.display();

    list.search(30);
    list.search(99);

    list.removeElement(20);
    list.display();

    list.removeElement(10);
    list.display();

    return 0;
}

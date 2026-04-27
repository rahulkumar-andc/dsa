#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

// ========== Stack ADT ==========
class Stack {
private:
    double data[100];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == 99; }

    void push(double val) {
        if (isFull()) { cout << "Stack Overflow.\n"; return; }
        data[++top] = val;
    }

    double pop() {
        if (isEmpty()) { cout << "Stack Underflow.\n"; return -1; }
        return data[top--];
    }

    double peek() {
        if (isEmpty()) return -1;
        return data[top];
    }
};

// ========== Postfix Evaluation ==========
double evaluatePostfix(const string& expr) {
    Stack s;
    for (char ch : expr) {
        if (ch == ' ') continue;
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            double b = s.pop();
            double a = s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
                default:  cout << "Unknown operator: " << ch << "\n";
            }
        }
    }
    return s.pop();
}

// ========== Prefix Evaluation ==========
double evaluatePrefix(const string& expr) {
    Stack s;
    // Traverse right to left
    for (int i = expr.size() - 1; i >= 0; i--) {
        char ch = expr[i];
        if (ch == ' ') continue;
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            double a = s.pop();
            double b = s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
                default:  cout << "Unknown operator: " << ch << "\n";
            }
        }
    }
    return s.pop();
}

int main() {
    // Postfix: 53+2* => (5+3)*2 = 16
    string postfix = "53+2*";
    cout << "Postfix Expression : " << postfix << "\n";
    cout << "Result             : " << evaluatePostfix(postfix) << "\n\n";

    // Prefix: *+532 => (5+3)*2 = 16
    string prefix = "*+532";
    cout << "Prefix Expression  : " << prefix << "\n";
    cout << "Result             : " << evaluatePrefix(prefix) << "\n";

    return 0;
}

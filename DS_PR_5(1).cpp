#include <iostream>
using namespace std;

#define SIZE 50

class Stack {
    char arr[SIZE];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == SIZE - 1);
    }

    void push(char ch) {
        if (isFull())
            cout << "Stack Overflow!" << endl;
        else
            arr[++top] = ch;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        } else {
            return arr[top--];
        }
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        } else {
            return arr[top];
        }
    }
};

// Function to check if expression is balanced
bool isBalanced(string exp) {
    Stack s;
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty())
                return false;

            char open = s.pop();

            if ((open == '(' && c != ')') ||
                (open == '{' && c != '}') ||
                (open == '[' && c != ']'))
                return false;
        }
    }
    return s.isEmpty();
}

int main() {
    Stack s;
    int choice;
    char ch;
    string expression;

    do {
        cout << "\n===== STACK OPERATIONS MENU =====";
        cout << "\n1. Push element";
        cout << "\n2. Pop element";
        cout << "\n3. Peek top element";
        cout << "\n4. Check if expression is well parenthesized";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to push: ";
                cin >> ch;
                s.push(ch);
                cout << ch << " pushed into stack." << endl;
                break;

            case 2:
                if (s.isEmpty())
                    cout << "Stack is empty!" << endl;
                else
                    cout << s.pop() << " popped from stack." << endl;
                break;

            case 3:
                if (s.isEmpty())
                    cout << "Stack is empty!" << endl;
                else
                    cout << "Top element is: " << s.peek() << endl;
                break;

            case 4:
                cout << "Enter expression: ";
                cin >> expression;
                if (isBalanced(expression))
                    cout << "Expression is Well Parenthesized ✅\n";
                else
                    cout << "Expression is NOT Well Parenthesized ❌\n";
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

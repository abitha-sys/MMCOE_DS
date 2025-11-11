#include <iostream>
using namespace std;

#define SIZE 50  // maximum size of stack

// Stack using array
class Stack {
public:
    char arr[SIZE];   // array to store stack elements
    int top;          // index of the top element

    // constructor
    Stack() {
        top = -1;
    }

    // function to check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // function to check if stack is full
    bool isFull() {
        return (top == SIZE - 1);
    }

    // function to push an element
    void push(char ch) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push more elements.\n";
        } else {
            top++;
            arr[top] = ch;
            cout << ch << " pushed into stack.\n";
        }
    }

    // function to pop (remove) top element
    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty.\n";
            return '\0'; // return null character if empty
        } else {
            char value = arr[top];
            top--;
            cout << value << " popped from stack.\n";
            return value;
        }
    }

    // function to see top element without removing it
    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return '\0';
        } else {
            return arr[top];
        }
    }
};

// function to check if an expression is balanced
bool isBalanced(string exp) {
    Stack s;
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // if opening bracket, push into stack
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        // if closing bracket, check matching pair
        else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty())
                return false;

            char open = s.pop();

            if ((open == '(' && c != ')') ||
                (open == '{' && c != '}') ||
                (open == '[' && c != ']'))
                return false;
        }
    }

    // if stack is empty at end, expression is balanced
    return s.isEmpty();
}

// main function
int main() {
    Stack s;
    int choice;
    char ch;
    string expression;

    do {
        cout << "\n=== STACK MENU ===";
        cout << "\n1. Push element";
        cout << "\n2. Pop element";
        cout << "\n3. Peek top element";
        cout << "\n4. Check expression (balanced or not)";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to push: ";
                cin >> ch;
                s.push(ch);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                ch = s.peek();
                if (ch != '\0')
                    cout << "Top element is: " << ch << endl;
                break;

            case 4:
                cout << "Enter expression: ";
                cin >> expression;
                if (isBalanced(expression))
                    cout << "✅ Expression is Balanced.\n";
                else
                    cout << "❌ Expression is NOT Balanced.\n";
                break;

            case 5:
                cout << "Goodbye! Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

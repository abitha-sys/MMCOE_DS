#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

// push function
void push(char ch) {
    top++;
    stack[top] = ch;
}

// pop function
char pop() {
    char ch = stack[top];
    top--;
    return ch;
}

// function to set operator priority
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

int main() {
    char infix[SIZE], postfix[SIZE];
    int i = 0, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i]) != '\0') {
        // if operand, add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // if '(', push it
        else if (ch == '(') {
            push(ch);
        }
        // if ')', pop until '('
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        // if operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    // pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // end string

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

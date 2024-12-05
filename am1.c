#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function prototypes
bool isEmpty();
bool isFull();
void push(char item);
char pop();
void displayStack();
bool isMatchingPair(char opening, char closing);
bool isValidExpression(const char* expression);

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(char item) {
    if (isFull()) {
        printf("Stack overflow, can't push '%c'\n", item);
    } else {
        stack[++top] = item;
        printf("Pushed '%c' to stack. ", item);
        displayStack();
    }
}

char pop() {
    if (isEmpty()) {
        printf("Stack underflow, nothing to pop\n");
        return '\0';
    } else {
        char item = stack[top--];
        printf("Popped '%c' from stack. ", item);
        displayStack();
        return item;
    }
}

void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Current stack: ");
        for (int i = 0; i <= top; i++) {
            printf("%c ", stack[i]);
        }
        printf("\n");
    }
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool isValidExpression(const char* expression) {
    char ch;
    for (int i = 0; expression[i] != '\0'; i++) {
        ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) {
                return false;
            }
            char topChar = pop();
            if (!isMatchingPair(topChar, ch)) {
                return false;
            }
        } else {
            printf("Invalid character '%c' detected\n", ch);
            return false;
        }
    }
    return isEmpty();
}

int main() {
    char expression[MAX];
    printf("Enter an expression (up to %d characters) with parentheses, braces, and brackets only: ", MAX - 1);
    scanf("%99s", expression);

    if (isValidExpression(expression)) {
        printf("Expression: %s is valid\n", expression);
    } else {
        printf("Expression: %s is invalid\n", expression);
    }

    return 0;
}
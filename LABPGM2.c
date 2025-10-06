// INFIX TO POSTFIX CONVERSION

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

// Pop function
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

//peek function
char peek(){
     if(top==-1) return -1;
     return stack[top];
}
// Function to return precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;   // Highest precedence
        case '(':
            return 0;
    }
    return -1;
}

// Function to return associativity
// 0 = Left-to-Right, 1 = Right-to-Left
int associativity(char op) {
    if (op == '^')
        return 1;   // Right-to-Left
    return 0;       // +, -, *, / → Left-to-Right
}
// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isalnum(c)) {
            // Operand → directly to postfix
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // discard '('
        }
        else {
            // Operator
            while (top != -1 &&
                   ((precedence(peek()) > precedence(c)) ||
                    (precedence(peek()) == precedence(c) &&
                     associativity(c) == 0))) {  // L-to-R
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main(){
     char infix[MAX],postfix[MAX];
     printf("Enter a valid parenthesized infix expression: ");
     scanf("%s",infix);
     infixToPostfix(infix,postfix);
     printf("Postfix Expression: %s\n",postfix);
     return 0;
}

// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

int stack2[MAX];
int top2 = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Error: Stack overflow!\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Error: Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

int pop2() {
    if (top2 == -1) {
        printf("Error: Stack underflow!\n");
        return -1;
    }
    return stack2[top2--];
}

void push2(int value) {
    if (top2 == MAX - 1) {
        printf("Error: Stack overflow!\n");
        return;
    }
    stack2[++top2] = value;
}

int main() {
    char input, temp[MAX];
    int value;
    while (1) {
        scanf("%c", &input);
        if (input == '\n')
            break;
        push(input);
        temp[top] = input;
    }
    while (top != -1) {
        value = pop();
        push2(value);
    }
    while (top2 != -1) {
        if (stack2[top2] != temp[top2]) {
            printf("no\n");
            return 0;
        }
        pop2();
    }
    printf("yes\n");
    return 0;
}
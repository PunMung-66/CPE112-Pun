// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

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



int main()
{
    char input;
    while (1) {
        scanf("%c", &input);
        if (input == '\n')
            break;
        if (input == '+' || input == '-' || input == '*' || input == '/' || input == '(' || input == ')')
        {
            if (input == ')')
            {
                while (top != -1 && stack[top] != '(')
                {
                    printf("%c", pop());
                }
                pop();
            }
            else if (input == '+' || input == '-')
            {
                while (top != -1 && stack[top] != '(')
                {
                    printf("%c", pop());
                }
                push(input);
            }
            else if (input == '*' || input == '/')
            {
                while (top != -1 && (stack[top] == '*' || stack[top] == '/'))
                {
                    printf("%c", pop());
                }
                push(input);
            }
            else
            {
                push(input);
            }
        }
        else
        {
            printf("%c", input);
        }
    }
    while (top != -1)
    {
        printf("%c", pop());
    } 
    return 0;
}
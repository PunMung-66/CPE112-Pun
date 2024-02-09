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

int main() {
    char input, *temp = (char*)malloc(MAX * sizeof(char)), value = 0;
    int i = 0, status = 0, count = 0;
    while (1) {
        scanf("%c", &input);
        if (input == '\n')
            break;
        if (input == '(' || input == '{' || input == '[' || input == ')' || input == '}' || input == ']' )
            push(input);
    }
    while (top != -1) {
        if (count == 0)
            value = pop();
        if (value == ')' || value == '}' || value == ']')
        {
            temp[i] = value;
            // printf("%c", temp[i]);
            status = 1;
            count = 0;
            i++;
        }
        else if ((value == '(' || value == '{' || value == '[') && status == 0)
        {
            printf("The string is not balanced\n");
            return 0;
        }
        else if (value == '(' || value == '{' || value == '[')
        {
            i--;
            while( value != ')' && value != '}' && value != ']' && top != -1 && i >= 0)
            {
                // printf("\n val_in: %c temp_in: %c \n", value, temp[i]);
                if (value == '(')
                {
                    if (temp[i] != ')')
                    {
                        printf("The string is not balanced\n");
                        return 0;
                    }
                }
                else if (value == '{')
                {
                    if (temp[i] != '}')
                    {
                        printf("The string is not balanced\n");
                        return 0;
                    }
                }
                else if (value == '[')
                {
                    if (temp[i] != ']')
                    {
                        printf("The string is not balanced\n");
                        return 0;
                    }
                }
                value = pop();
                i--;
            }
            status = 0;
            count = 1;
            i = 0;
            // printf("PASS\n");
        }
    }
    if (status == 1)
    {
        printf("The string is not balanced\n");
        return 0;
    }
    printf("The string is balanced\n");
    free(temp);
    return 0;
}
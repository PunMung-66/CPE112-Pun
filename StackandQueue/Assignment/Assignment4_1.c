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

void convert(int n, int base, char base36[])
{
    if (n == 0)
    {
        return;
    }
    convert(n / base, base, base36);
    printf("%c", base36[n % base]);
}

int main()
{
    char n[MAX], c;
    int base, num = 0, i = 0;
    char base36[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%s", n);
    while (n[i+1] != '\0')
        i++;
    while (i >= 0)
    {
        push(n[i]);
        i--;
    }
    while (top != -1)
    {
        c = pop();
        num = num * 10;
        num += c - '0';
    }
    scanf("%d", &base);
    if (base > 36 || base < 2 || num < 1)
    {
        printf("invalid");
        return 0;
    }
    convert(num, base, base36);
    return 0;
}
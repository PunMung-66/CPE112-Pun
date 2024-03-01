// Problem 1: Set 
// 66070503436 Punnawat Mungkalarungsi

#include <stdio.h>
#include <stdlib.h>

typedef struct sortedset
{
    int *elements;
    int size;
} sortedset;

void init(struct sortedset *s, int size);
int checkDuplicate(struct sortedset *s, int target);
void insertElement(struct sortedset *s, int newNum);
void printArray(struct sortedset *s);


void init(struct sortedset *s, int size)
{
    // Big (O) = n
    s->elements = (int *)calloc(size , sizeof(int)); // allocate memory for the array and initialize it to 0
    s->size = 0;
}

int checkDuplicate(struct sortedset *s, int target)
{
    // Big (O) = n
    for (int i = 0; i < s->size; i++) // check if the target is already in the array
        if (s->elements[i] == target)
            return 1;
    return 0; // if not found
}

void insertElement(struct sortedset *s, int newNum)
{
    // Big (O) = n
    if (checkDuplicate(s, newNum) == 0) // if the new number is not in the array
    {
        s->elements[s->size] = newNum;// insert the new number
        s->size++;// increase the size of the array
    }
}

void printArray(struct sortedset *s)
{
    // Big (O) = n
    printf("%d\n", s->size); // print the size of the array
    printf("{");
    for (int i = 0; i < s->size; i++)
    {
        printf("%d", s->elements[i]); // print the elements of the array
        if (i != s->size - 1) // if it's not the last element
            printf(", ");
    }
    printf("}");
}

void sort(struct sortedset *s)
{
    // Big (O) = n^2
    for (int i = 0; i < s->size; i++)
    {
        for (int j = i + 1; j < s->size; j++)
        {
            if (s->elements[i] > s->elements[j])
            {
                int temp = s->elements[i];
                s->elements[i] = s->elements[j];
                s->elements[j] = temp;
            }
        }
    }
}


int main()
{
    int n;
    sortedset s;
    scanf("%d", &n); // read the size of the array
    init(&s, n); // initialize the array
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num); // get the elements of the array
        insertElement(&s, num); // insert the elements of the array
    }
    sort(&s); // sort the array
    printArray(&s); // print the array
    return 0;
}
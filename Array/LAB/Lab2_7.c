// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <string.h> 

struct dict
{
    char value[100];
    char key[100];
};

void editdict(struct dict *dic, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(dic[i].key, dic[j].key) == 0)
            {
                struct dict temp;
                strcpy (temp.value , dic[i].value);
                strcpy (dic[i].value , dic[j].value);
                strcpy (dic[j].value , temp.value);
                count++;
            }
        }
    }
    if (count == 0)
        printf("No change\n");
}
void printdict(struct dict *dic, int size)
{ // for printing the output
    for (int i = 0; i < size; i++)
        printf("%s : %s\n", dic[i].key, dic[i].value);
}
int main()
{
    int size;
    scanf("%d", &size);
    struct dict dic[size + 1]; // you can do this to declare structure in the array
    // write your code here
    for (int i = 0; i < size + 1; i++)
    {
        scanf("%s", dic[i].key);
        scanf("%s", dic[i].value);
    }

    editdict(dic, size + 1);
    printdict(dic, size);
}
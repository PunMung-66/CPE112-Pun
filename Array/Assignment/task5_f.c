// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <string.h> 
#include <math.h>

struct dict
{
    char score[100];
    char name[100];
};

int max(struct dict *dic, int size)
{
    int index = 0;
    for (int i = 0; i < size; i++)
        if (atof(dic[index].score) < atof(dic[i].score))
            index = i;
    printf("%s ", dic[index].name);
    return index;
}

int min(struct dict *dic, int size)
{
    int index = 0;
    for (int i = 0; i < size; i++)
        if (atof(dic[index].score) > atof(dic[i].score))
            index = i;
    printf("%s", dic[index].name);
    return index;
}

double mean(struct dict *dic, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += atof(dic[i].score);
    return sum / size;
}

double sd(struct dict *dic, int size)
{
    double sum = 0;
    double m = mean(dic, size);
    for (int i = 0; i < size; i++)
        sum += (atof(dic[i].score) - m) * (atof(dic[i].score) - m);
    sum /= (size);
    sum = sqrt(sum);
    printf("%0.2lf ", m);
    printf("%0.2lf ", sum);
    return sum;
}

int main()
{
    int size;
    scanf("%d", &size);
    struct dict dic[size]; // you can do this to declare structure in the array
    // write your code here
    for (int i = 0; i < size; i++)
    {
        scanf("%s", dic[i].name);
        scanf("%s", dic[i].score);
    }
    mean(dic, size);
    sd(dic, size);
    max(dic, size);
    min(dic, size);
    return 0;
}
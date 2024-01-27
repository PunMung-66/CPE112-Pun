// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>
#include <math.h>

struct dict
{
    char score[100];
    char name[100];
};

double atof_make(char *str)
{
    double val = 0;
    int i = 0;
    int sign = 1;
    while (str[i] == ' ')
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        val = val * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
        i++;
    double power = 1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        val = val * 10 + (str[i] - '0');
        power *= 10;
        i++;
    }
    return sign * val / power;
}

int max_m(struct dict *dic, int size)
{
    int index = 0;
    for (int i = 0; i < size; i++)
        if (atof_make(dic[index].score) < atof_make(dic[i].score))
            index = i;
    printf("%s ", dic[index].name);
    return index;
}

int min_m(struct dict *dic, int size)
{
    int index = 0;
    for (int i = 0; i < size; i++)
        if (atof_make(dic[index].score) > atof_make(dic[i].score))
            index = i;
    printf("%s", dic[index].name);
    return index;
}

double mean(struct dict *dic, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += atof_make(dic[i].score);
    return sum / size;
}

double sd(struct dict *dic, int size)
{
    double sum = 0;
    double m = mean(dic, size);
    for (int i = 0; i < size; i++)
        sum += (atof_make(dic[i].score) - m) * (atof_make(dic[i].score) - m);
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
    max_m(dic, size);
    min_m(dic, size);
    return 0;
}
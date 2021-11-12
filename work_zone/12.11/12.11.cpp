#include <iostream>

int main()
{

    int i, j, step, n, mas[] = { 8,5,4,2,1 }, mas1[] = { 8,5,4,2,1 };
    float k = 1.274;
    n = sizeof(mas) / sizeof(int);
    step = n - 1;

    while (step >= 1)
    {
        for (int i = 0; i < n - step; i++)
        {
            if (mas[i] > mas[i + step])
            {
                mas[i] = mas[i] ^ mas[i + step];
                mas[i + step] = mas[i] ^ mas[i + step];
                mas[i] = mas[i] ^ mas[i + step];
            }
        }
        step /= k;
    }

    for (i = 0; i < n; i++)
    {
        printf("%i ", mas[i]);
    }

 //-----------------------------------------------------------

    for (j = 0; j < n - 1; j++)
    {
        for (i = 0; i < n - j - 1; i++)
        {
            if (mas[i] > mas[i + 1])
            {
                mas[i] = mas[i] ^ mas[i + 1];
                mas[i + 1] = mas[i] ^ mas[i + 1];
                mas[i] = mas[i] ^ mas[i + 1];
            }
        }
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%i ", mas[i]);
    }

    return 0;
}

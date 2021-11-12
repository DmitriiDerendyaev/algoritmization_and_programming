#include <iostream>

int main()
{

    int i, j, step, n, mas[] = { 8,5,4,2,1, 45,56,89,16,10,67,90,98,198 }, mas1[] = { 8,5,4,2,1, 45,56,89,16,10,67,90,98,198 };
    int count_swap = 0, count_cycle = 0;
    float k = 1.274;
    n = sizeof(mas) / sizeof(int);
    step = n - 1;
    int flag = 0;
    while (step > 1 || flag == 1)
    {
        flag = 0;
        count_cycle++;
        for (int i = 0; i < n - step; i++)
        {
            count_cycle++;
            if (mas[i] > mas[i + step])
            {
                flag = 1;
                count_swap++;
                mas[i] = mas[i] ^ mas[i + step];
                mas[i + step] = mas[i] ^ mas[i + step];
                mas[i] = mas[i] ^ mas[i + step];
            }
        }
        step /= k;
        //flag = 0;
        if (step == 0)
        {
            step = 1;
        }
    }

    printf("%i %i\n", count_swap, count_cycle);

    for (i = 0; i < n; i++)
    {
        printf("%i ", mas[i]);
    }

 //-----------------------------------------------------------

    count_swap = 0;
    count_cycle = 0;

    for (j = 0; j < n - 1; j++)
    {
        count_cycle++;
        for (i = 0; i < n - j - 1; i++)
        {
            count_cycle++;
            if (mas[i] > mas[i + 1])
            {
                count_swap++;
                mas[i] = mas[i] ^ mas[i + 1];
                mas[i + 1] = mas[i] ^ mas[i + 1];
                mas[i] = mas[i] ^ mas[i + 1];
            }
        }
    }

    printf("\n");

    printf("%i %i\n", count_swap, count_cycle);

    for (i = 0; i < n; i++)
    {
        printf("%i ", mas[i]);
    }

    return 0;
}

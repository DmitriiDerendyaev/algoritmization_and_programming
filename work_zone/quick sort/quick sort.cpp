#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

void qsort(int* arr, int left, int right)
{
    int i = left, j = right;
    int temp, pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }

            i++; j--;
        }

    };

    if (left < j) qsort(arr, left, j);
    if (i < right) qsort(arr, i, right);
}

//-------------------------------------------------------------------

int main()
{
    int Arr[SIZE];

    // Заполнение массива случайными числами
    for (int i = 0; i < SIZE; i++) Arr[i] = rand() % 100;

    // Вывод элементов массива до сортировки
    for (int i = 0; i < SIZE; i++) printf("%3d ", Arr[i]); printf("\n");

    qsort(Arr, 0, SIZE - 1); // вызов функции сортировки

    // Вывод элементов массива после сортировки
    for (int i = 0; i < SIZE; i++) printf("%3d ", Arr[i]); printf("\n");

    getchar(); return 0;
}
#include <iostream>//подключение необходимых библиотек

using namespace std;//определение пространства имен

#define n 5//определение идентификатора n = 5

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
    int Arr[] = { 5, 7, 8, 4, 9 };

    // Вывод элементов массива до сортировки
    for (int i = 0; i < n; i++)
        cout << Arr[i] << ' ';
    cout << endl << endl;

    qsort(Arr, 0, n - 1); // вызов функции сортировки

    // Вывод элементов массива после сортировки
    for (int i = 0; i < n; i++)
        cout << Arr[i] << ' ';
    cout << endl << endl;

    system("pause");
    
    return 0;
}
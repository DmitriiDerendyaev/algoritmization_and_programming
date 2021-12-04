#include <iostream>
using namespace std;

void qsort(int* arr, int b, int e) {
    int piv = arr[(b + e) / 2];
    int l = b;
    int r = e;
    while (l <= r)
    {
        while (arr[l] < piv) l++;
        while (arr[r] > piv) r--;
        if (l <= r) // условие 
        {
            int t = arr[l];
            arr[l] = arr[r];
            arr[r] = t;
            l++;
            r--;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int b, e, l, r, t, arr[] = { 5, 7, 8, 4, 9 };
    if (b < r) {
        qsort(arr, b, r);
    }
    if (l < e)
    {
        qsort(arr, l, e);
    }

    for (int i = 0; i < 5; i++)
        cout << arr[i] << ' ';

    return 0;
}



#include <iostream>

using namespace std;

int main()  
{
    int N = 7, j, i, buf, min;
    int mas[] = { 6, 2, 1, 10, 3, 7, 4 };

    for (i = 0; i < N - 1; i++) {
        for (j = i + 1, min = i; j < N; j++) {
            if (mas[j] < mas[min])
                min = j;
        }
        buf = mas[i];
        mas[i] = mas[min];
        mas[min] = buf;
    }    
    
    //-------------------------------------------------
    int mas2[] = { 6, 2, 1, 10, 3, 7, 4 };
    int n, nte, min2, temp, gr = 0;

    n = sizeof(mas2) / sizeof(int);

    while (gr < n - 1)
    {
        min2 = gr;
        nte = gr + 1;
        while (nte < n)
        {
            if (mas2[min2] < mas2[nte])
            {
                min2 = nte;
            }
            nte++;
        }
        temp = mas2[gr];
        mas[gr] = mas[min2];
        mas[min2] = temp;
        gr++;
    }

    for (gr = 0; gr < n; gr++)
    {
        cout << mas2[gr] << ' ';
    }
    cout << ' ';

    return 0;
}
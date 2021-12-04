#include <iostream>

using namespace std;

int main()
{
    int N, j = 2, i = 1, buf;
    //int *mas = new int[7];
    int mas[]{ 6, 4, 1, 5, 3, 7, 2 };
    N = 7;

    while (i < N) {
        if (mas[i - 1] > mas[i]) 
        {
            buf = mas[i];
            mas[i] = mas[i - 1];
            mas[i - 1] = buf;
            i--;
            if (i > 0) 
                continue;

        }
        
        i = j++;
    }    

    for (int i = 0; i < N; i++)
    {
        cout << mas[i] << ' ';
    }

    cout << endl  << endl;



    //------------------------------------------------------

    int n;
    j = 2, i = 1, buf;
    //int *mas = new int[7];
    int mas2[]{ 6, 4, 1, 5, 3, 7, 2 };
    n = sizeof(mas2) / sizeof(int);

    for(i = j; i < n; j++)
    {
        if (mas2[i - 1] > mas2[i])
        {
            buf = mas2[i];
            mas2[i] = mas2[i - 1];
            mas2[i - 1] = buf;
            i--;
            if (i > 0)
                continue;
        }
        i = j++;
    }

    for (int i = 0; i < N; i++)
    {
        cout << mas[i] << ' ';
    }


    return 0;

}
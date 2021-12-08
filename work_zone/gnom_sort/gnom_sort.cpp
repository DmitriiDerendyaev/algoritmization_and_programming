#include <iostream>

using namespace std;

int main()
{
    int i, buf, n, m[]{ 4,3,1,2 };
    n = sizeof(m) / sizeof(int);

    i = 1;

    while (i < n)
    {
        if (m[i] > m[i - 1] || i == 0)
        {
            i++;
            continue;
        }
        buf = m[i];
        m[i] = m[i - 1];
        m[i - 1] = buf;
        i--;
    }

    //while (i < n)
    //{
    //    if (m[i] > m[i - 1] || i == 0)
    //    {
    //        i++;
    //        //continue;
    //    }
    //    else
    //    {
    //        buf = m[i];
    //        m[i] = m[i - 1];
    //        m[i - 1] = buf;
    //        i--;
    //    }
    //}

    for (int i = 0; i < n; i++)
    {
        cout << m[i] << ' ';
    }

    system("pause");

    return 0;
}

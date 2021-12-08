#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;

int main()
{
    int j = 2, i = 1, buf;
    vector<int> vec;
    int q, peremen;

    cout << "Enter the amount of element:";

    cin >> q;
    for (int k = 0; k < q; k++)
    {
        peremen = rand() % q + 1;
        vec.push_back(peremen);
    }

    cout << "Array before sort:" << endl;
    for (int i = 0; i < q; i++)
        cout << vec[i] << ' ';
    cout << endl << endl;

    auto t1 = Clock::now();

    while (i < vec.size()) {//начало цикла прохода по всему массиву
        if (vec[i - 1] > vec[i]) //проверка услови€, если предыдущий элемент больше текущего
        {
            buf = vec[i];//производим обмен значений переменнызх посредством буферной переменной
            vec[i] = vec[i - 1];
            vec[i - 1] = buf;
            i--;//т.к. мы попали в условие, значит, у нас произошла перестановка и нам важно пон€ть, меньше ли все предыдущие значени€ и правильный ли там пор€док, делаем шаг назад
            if (i > 0) //если i больше нул€, продолжаем итерацию цикла
                continue;

        }

        i = j++;//приравниваем новый номер к заранее сохраненному(это позвол€ет алгоритму перепрыгивать на то место, откуда он начал уходить в анализ предыдущих элементов))
    }

    auto t2 = Clock::now();

    cout << "Array after sort:" << endl;
    for (int i = 0; i < q; i++)
        cout << vec[i] << ' ';

    cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

    system("pause");

    return 0;

}
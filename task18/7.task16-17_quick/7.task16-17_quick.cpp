#include <iostream>//подключение необходимых библиотек
#include <vector>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;

vector<int> vec;
int q, peremen;

void qsort(vector<int>& vec, int left, int right)//объ€вление подфункции сортировки
{
    int i = left, j = right;//объ€вление переменных крайнего левого положени€ и крайнего праввого положени€
    int temp, pivot = vec[(left + right) / 2];//поиск центра(поиск опорного элемента)

    while (i <= j)//цикл выполн€етс€, пока границы не сомкнутс€
    {
        while (vec[i] < pivot) //если значение анализируемого элемента из левой части меньше значени€ опорного элемента
            i++;//мы сдвигаем левую границу на одну единицу вправо
        while (vec[j] > pivot) //если значение анализируемого элемента из правой части больше значени€ опорного элемента
            j--;//мы сдвигаем правую границу на одну единицу влево
        //сдвигаем границы к центру - к опорному элементу
        if (i <= j)
        {
            if (vec[i] > vec[j])//выполнение обмена, если значение текущего элемента в левой части больше значени€ текущего элемента в правой части
            {
                temp = vec[i];//обмен значений переменных с использованием буферной переменной temp
                vec[i] = vec[j];
                vec[j] = temp;
            }

            i++;
            j--;//уменьшнеие границ диапазона
        }

    }

    if (left < j)
        qsort(vec, left, j);//если обнаружено нарушение пор€дка в одной из частей, вызываетс€ функци€ сортировки определенной части
    if (i < right)
        qsort(vec, i, right);//если обнаружено нарушение пор€дка в одной из частей, вызываетс€ функци€ сортировки определенной части
}

//-------------------------------------------------------------------

int main()//начало главной функции
{
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

    qsort(vec, 0, vec.size() - 1); // вызов функции сортировки

    auto t2 = Clock::now();

    cout << "Array after sort:" << endl;
    for (int i = 0; i < q; i++)
        cout << vec[i] << ' ';

    cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

    system("pause");

    return 0;
}
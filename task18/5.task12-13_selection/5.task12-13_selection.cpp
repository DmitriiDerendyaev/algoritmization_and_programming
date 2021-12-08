#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;


int main()
{

    vector<int> vec;//îáúÿëåíèå âåòîðà(ìàññèâà)
    int q, peremen;

    int nte, min2, temp, gr = 0;//подготовка необходимых переменных, в том числе размера массива, параметров циклов, буферных переменных и индекса минимального элемента

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


    while (gr < vec.size() - 1)//начало цикла прохода по всему массиву от первого элемента до последнего с индексом N-1
    {
        min2 = gr;//присваивание переменной min индекса первого элемента на данном этапе
        nte = gr + 1;//номер текущего элмента равен границе исследуемого массива + 1(для альнейшего анализа)
        while (nte < vec.size())//вложенный цикл будет выполняться, пока номер текущего элемента меньше размера самого массива
        {
            if (vec[min2] > vec[nte])//сравнение значений текущего элемента и значения элемента неотсортированной части(увеличение до тех пор, пока не закончится массив)
            {
                min2 = nte;//рписваивание переменной min2 номер аминимального элемента
            }
            nte++;//(увеличение номера текущего элемента до тех пор, пока не закончится массив)
        }
        temp = vec[gr];//производение обмена значений переменных, используя буферную переменную buf
        vec[gr] = vec[min2];
        vec[min2] = temp;
        gr++;//продвижение по массиву на шаг вперед
    }

    auto t2 = Clock::now();

    cout << "Array after sort:" << endl;
    for (int i = 0; i < q; i++)
        cout << vec[i] << ' ';

    cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

    system("pause");

    return 0;//завершение программы
}
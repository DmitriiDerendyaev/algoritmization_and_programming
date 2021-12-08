#include <iostream>//подключение необходимых библиотек
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;//объявение стандартного пространства имен

typedef std::chrono::high_resolution_clock Clock;

vector<int> vec1;//объявление переменных
int n;
float k = 1.247;
int q, peremen;

int main()//начало основной программы
{

	cout << "Enter the amount of element:";

	cin >> q;
	for (int k = 0; k < q; k++)
	{
		peremen = rand() % q + 1;
		vec1.push_back(peremen);
	}

	cout << "Array before sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << vec1[i] << ' ';
	cout << endl << endl;

	auto t1 = Clock::now();

	n = vec1.size();//определение размера массива
	int step = n - 1;//инициализация первого шага(крайняя точка массива)
	while (step >= 1)//инициализация внешнего цикла while до момента, пока step больше 1
	{
		int i = 0;//инициализация счетчика внутреннего цикла
		while (i < n - step)//внутренний цикл выполнет функцию прохода от начала вектора до конца(в последствии размер массива - шаг)
		{
			if (vec1[i] > vec1[i + step])//если первый элемент больше элемента +step произвести обмен
				swap(vec1[i], vec1[i + step]);//выполнение перемещения элементов вектора по индексам, заданным в условии
			i++;
		}
		step /= k;//уменьшение шага

	}

	auto t2 = Clock::now();

	cout << "Array after sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << vec1[i] << ' ';

	cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

	system("pause");

	return 0;
}
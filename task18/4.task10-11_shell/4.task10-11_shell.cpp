#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;


int main()
{	

	vector<int> vec;//объ€ление ветора(массива)
	int q, peremen;

	int i = 0, j = 0, x = 0, step = 0;//подготовка переменных к обработке массива mas2 с помощью цикла while
	
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

	step = vec.size() / 2;//вычисл€ем размер шага
	while (step > 0)//цикл выпол€нетс€, пока значение шага болльше нул€
	{
		i = step;// переходим к обработке элемента с номером шага
		while (i < vec.size())//выполн€ем цикл, пока исследуемый элемент меньше размера массива
		{
			x = vec[i];//в буферную переменную помещаем значение исслудуемого элемента
			j = i;//присвоение номеру текущего элемента номер исследуемого элемента
			while (j >= step)//выполнение цикла, пока номер исследуемого элемента больше шага step
			{
				if (x < vec[j - step])//сравниваем значение анализируемого элемента с элементом, отличающимс€ на шаг(по индексу)
				{
					vec[j] = vec[j - step];////ставим на место j-го элемента элемент с индексом j-шаг
					j = j - step;//ументшаем значение индекса j на величину шага
				}
				else
					break;////выходим из текущей итерации, если значение анализируемого элемента больше, чем значение элемента отличающегос€ на step
			}
			vec[j] = x;//возвращаем значение буфера
			i++;//переходим к следующем элементу
		}
		step /= 2;//уменьшаем шаг
	}

	auto t2 = Clock::now();

	cout << "Array after sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << vec[i] << ' ';

	cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

	system("pause");

	return 0;
}
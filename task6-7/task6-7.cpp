#include <iostream>//подключение необходимых библиотек
#include <vector>
#include <algorithm>

using namespace std;//объ€вение стандартного пространства имен

vector<int> vec1;//объ€вление переменных
int n;
float k = 1.247;


void reading(void)//инициализации функции заполнени€ вектора(с клавиатуры)
{
	int el;//объ€вление промежуточной переменной, куда будет буферно записыватьс€ переменна€ дл€ очередного элемента вектора
	while (cin >> el)//начало цикла while и работа его до тех пор, пока ввод€тс€ значени€ с клавиатуры(Stop: Ctrl+Z) - Ќ≈ –≈ ќћ≈Ќƒ”≈“—я
	{
		if (el != 0)//конец строки дл€ опеределенной задачи по символу 0
			vec1.push_back(el);//внесение очередного элемента в конец вектора
		else
			break;//если был нажат 0, то выход из подпрограммы записи вектора
	}
}

void printing(void)//инициализаци€ функции печати/вывода элементов на экран
{
	for (int i = 0; i < vec1.size(); i++)//цикл вывода элементов на экран с индексом от начала до конца вектора(по размеру массива)
	{
		cout << vec1[i] << " ";//печать значени€
	}
	cout << endl;//перенос строки
}

void sort_for(void)//инициализаци€ функции сортировки массива с помощью цикла for
{
	cout << "When finished typing, press CTRL + Z or enter 0 to contine next task:" << endl;//предупреждение
	reading();
	n = vec1.size();
	for (int step = n - 1; step >= 1; step /= k)
	{
		for (int i = 0; i < n - step; i++)
		{
			if (vec1[i] > vec1[i + step])
				swap(vec1[i], vec1[i + step]);
		}
	}
	printing();
}

void sort_while(void)
{
	cout << "When finished typing, press CTRL + Z:" << endl;
	reading();
	n = vec1.size();
	int step = n - 1;
	while(step >= 1)
	{
		int i = 0;
		while (i < n - step)
		{
			if (vec1[i] > vec1[i + step])
				swap(vec1[i], vec1[i + step]);
			i++;
		}
		step /= k;
		
	}
	printing();
}

int main()
{
	cout << "Curren array sorted by for:" << endl;
	sort_for();

	vec1.clear();

	cout << "Curren array sorted by while:" << endl;
	sort_while();

	return 0;
}
#include <iostream>//подкючение необходимых библиотек
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;//определение пространства имен

typedef std::chrono::high_resolution_clock Clock;

int el, buf, i, j;//объ€вление переменных, участвующих в обработке массива
vector<int> vec;//объ€ление ветора(массива)
int q, peremen;

int main()//начало основной программы
{
	setlocale(LC_ALL, "Russian");//установка локали, поодержка –усского €зыка

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

	for (int i = 1; i < vec.size(); i++)//сортировка массива начинаетс€ со второго элемента
	{
		buf = vec[i];//помещаем в буферную €чейку значение числа, которое будем в дальнейшем анализировать
		j = i;//внутренний цикл начинаетс€ с номера анализируемого элемента
		while (j > 0 and buf < vec[j - 1])//цилк выполн€етс€ пока элемент не выходит за его пределы
			//и он не больше, чем номер анализируемого элемента j и значение анализируемого элемента меньше, чем предыдущее
		{
			vec[j] = vec[j - 1];//если условие все-таки выполн€етс€ то элементы мен€ютс€ местами
			j--;//уменьшение на единицу номера анализируемого элемента дл€ того, чтобы произвести проверку элемента, расположенного ближе к началу
		}
		vec[j] = buf;//перчемещение элемента буферной €чейки в €чейку текущего элемента
	}

	auto t2 = Clock::now();

	cout << "Array after sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << vec[i] << ' ';

	cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

	system("pause");

	return 0;//завершение программы
}
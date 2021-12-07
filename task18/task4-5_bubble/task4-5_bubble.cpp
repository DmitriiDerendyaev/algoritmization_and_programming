#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	vector<int> array2;
	int q, peremen;
	int i, j, buf1 = 0, buf2 = 0;//объявление всех переменных, включая парметр массивов, массивы, буферные ячейки памяти

	clock_t start;
	double duration;


	cout << "Enter the amount of element:";

	cin >> q;
	for (int k = 0; k < q; k++)
	{
		peremen = rand() % q + 1;
		array2.push_back(peremen);
	}

	cout << "Array before sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << array2[i] << ' ';
	cout << endl << endl;

	start = clock();

	i = 0;//обнуление переменных-параметров цикла while
	j = 0;
	while (i < q - 1)//запуск внешнего цикла while
	{
		while (j < q - 1)//запуск внутреннего цикла while
		{
			if (array2[j] > array2[j + 1])//сопоставление текущего и последующего элемента массива
				/*если текущий элемент больше последующего,
				необходимо произвести перестановку, используя дополительную переменную*/
			{
				buf2 = array2[j];//перемещение значений элементов массива
				array2[j] = array2[j + 1];
				array2[j + 1] = buf2;
			}
			j++;//увеличение параметра цикла после исполнения программы
		}
		j = 0;//обнуление параметра внутренного цикла
		i++;//увеличение параметра цикла после исполнения программы
	}

	duration = ((double)clock() - (double)start)/*/(double)CLOCKS_PER_SEC*/;//без "(double)CLOCKS_PER_SEC" в миллисекундах
	cout << "Array after sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << array2[i] << ' ';

	cout << setprecision(5);
	cout << endl << "Duration is: " << duration << endl;

	system("pause");

	return 0;
}
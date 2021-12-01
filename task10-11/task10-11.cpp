#include <iostream>

using namespace std;

int main()
{
	int i, j, x, step;
	int mas[] = {6,1,5,2,3,8,20};
	
	int n = sizeof(mas) / sizeof(int);//получаем размер массива mas

	for (step = n / 2; step > 0; step /= 2)//рассчитываем величину шага, изначально определяем его, как половину размера исходгого массива
	{//выполняем массив до тех пор, пока шаг больше 0
		for (i = step; i < n; i++)
		{
			x = mas[i];//используем буферную переменную, куда помещаем значение анализируемого элемента
			for (j = i; j >= step; j -= step)//номеру текущего элемента присваивается номер анализируемого элемента
			{
				if (x < mas[j - step])//сравниваем значение анализируемого элемента с элементом, отличающимся на шаг(по индексу)
				{
					mas[j] = mas[j - step];//ставим на место j-го элемента элемент с индексом j-шаг
				}
				else
					break;
			}
			mas[j] = x;//если 
		}
	}

	for (i = 0; i < n; i++)
	{
		cout << mas[i] << ' ';
	}
	cout << endl;
	cout << endl;

	//-------
	int mas2[] = { 6,1,5,2,3,8,20 };
	int n2 = sizeof(mas2) / sizeof(int);//получаем размер массива mas
	step = n2 / 2;
	while (step > 0)
	{
		i = step;
		while (i >= n2)
		{
			x = mas2[i];
			j = i;
			while (j >= step)
			{
				if (x < mas2[j - step])
				{
					mas2[j] = mas2[j - step];
					j = j - step;
				}
				else
					break;
			}
			mas2[j] = x;
			i++;
		}
		step /= 2;
	}
	for (i = 0; i < n2; i++)
	{
		cout << mas2[i] << ' ';
	}
	cout << endl;

	return 0;
}
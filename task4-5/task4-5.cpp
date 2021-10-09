#include <iostream>

using namespace std;

int i, j, n, buf, array[] = {7,5,4,6,1,2,3}, array_sort[7];

void task1(int array, int* array_sort)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				buf = array[j];
				array[j] = array[j + 1];
				array[j + 1] = buf;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		array_sort[i] = array[i];
	}
}


int main()
{
	int z; 
	cin >> z;

	switch (z)
	{
	case 1:
	{
		task1(array, &array_sort);
	}
	}
	




	return 0;
}
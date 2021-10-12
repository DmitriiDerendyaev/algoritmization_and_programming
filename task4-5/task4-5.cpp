#include <iostream>

using namespace std;

int i, j, buf1 = 0, buf2 = 0, array1[] = { 7,5,4,6,1,2,3 }, array2[] = {8,7,5,1,9,4};
int n1 = sizeof(array1) / sizeof(int);
int n2 = sizeof(array2) / sizeof(int);

void printing_for(int array1[])
{
	for (int i = 0; i < n1; i++)
		cout << array1[i] << " ";
}

void printing_while(int array2[])
{
	for (int i = 0; i < n2; i++)
		cout << array2[i] << " ";
}

void task_for(int array1[])
{
	for (int i = 0; i < n1 - 1; i++)
		for (int j = 0; j < n1 - 1; j++)
			if (array1[j] > array1[j + 1])
			{
				buf1 = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = buf1;
			}

	printing_for(array1);
}

void task_while(int array2[])
{
	i = 0;
	j = 0;
	while (i < n2 - 1)
	{
		while (j < n2 - 1)
		{
			if (array2[j] > array2[j + 1])
			{
				buf2 = array2[j];
				array2[i] = array2[j + 1];
				array2[j + 1] = buf2;
			}
			j++;
		}
		i++;
	}

	printing_while(array2);
}

int main()
{
	cout << "Print sorted array by for:" << endl;
	task_for(array1);

	cout << endl << "Print sorted array by while:" << endl;
	task_while(array2);

	return 0;
}
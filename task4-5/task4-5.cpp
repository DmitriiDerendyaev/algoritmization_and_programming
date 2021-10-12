#include <iostream>

using namespace std;

int i, j, buf, array1[] = {7,5,4,6,1,2,3};
int n = sizeof(array1) / sizeof(int);
//void printing(int array1[])
//{
//	for (int i = 0; i < sizeof(array1); i++)
//		cout << array1[i] << " ";
//
//}

void task_for(int array1[])
{
	//int i, j, n, buf, array1[] = { 7,5,4,6,1,2,3 };

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)//delet i!!!!!!!!!!!!!!
			if (array1[j] > array1[j + 1])
			{
				buf = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = buf;
			}

	for (int i = 0; i < n; i++)
		cout << array1[i];
	//printing(array1);
}

int main()
{

	task_for(array1);
	//cout << "Do you exist?";
	return 0;
}
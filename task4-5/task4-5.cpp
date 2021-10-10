#include <iostream>

using namespace std;

//int i, j, n, buf, array1[] = {7,5,4,6,1,2,3};

//void printing(int array1[])
//{
//	for (int i = 0; i < sizeof(array1); i++)
//		cout << array1[i] << " ";
//
//}

//void task_for(/*int array1[]*/)
//{
//	n = sizeof(array1);
//	for(int i = 0; i < n - 1; i++)
//		for (int j = 0; j < n - i - 1; j++)
//			if (array1[i] > array1[i + 1])
//			{
//				buf = array1[i];
//				array1[i] = array1[i + 1];
//				array1[i + 1] = buf;
//			}
//
//	for (int i = 0; i < n; i++)
//		cout << array1[i];
//	//printing(array1);
//}

int main()
{

	int i, j, n, buf, array1[] = { 7,5,4,6,1,2,3 };

	n = sizeof(array1) / sizeof(int);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (array1[i] > array1[i + 1])
			{
				buf = array1[i];
				array1[i] = array1[i + 1];
				array1[i + 1] = buf;
			}

	for (int i = 0; i < n; i++)//тестовый вывод
		cout << array1[i] << ".";
	//task_for();
	cout << "Do you exist?";
	return 0;
}
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	vector<int> array2;
	int q, peremen;
	int i, j, buf1 = 0, buf2 = 0;//���������� ���� ����������, ������� ������� ��������, �������, �������� ������ ������

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

	i = 0;//��������� ����������-���������� ����� while
	j = 0;
	while (i < q - 1)//������ �������� ����� while
	{
		while (j < q - 1)//������ ����������� ����� while
		{
			if (array2[j] > array2[j + 1])//������������� �������� � ������������ �������� �������
				/*���� ������� ������� ������ ������������,
				���������� ���������� ������������, ��������� ������������� ����������*/
			{
				buf2 = array2[j];//����������� �������� ��������� �������
				array2[j] = array2[j + 1];
				array2[j + 1] = buf2;
			}
			j++;//���������� ��������� ����� ����� ���������� ���������
		}
		j = 0;//��������� ��������� ����������� �����
		i++;//���������� ��������� ����� ����� ���������� ���������
	}

	duration = ((double)clock() - (double)start)/*/(double)CLOCKS_PER_SEC*/;//��� "(double)CLOCKS_PER_SEC" � �������������
	cout << "Array after sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << array2[i] << ' ';

	cout << setprecision(5);
	cout << endl << "Duration is: " << duration << endl;

	system("pause");

	return 0;
}
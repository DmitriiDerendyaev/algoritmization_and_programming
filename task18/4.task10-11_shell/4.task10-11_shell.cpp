#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;


int main()
{	

	vector<int> vec;//��������� ������(�������)
	int q, peremen;

	int i = 0, j = 0, x = 0, step = 0;//���������� ���������� � ��������� ������� mas2 � ������� ����� while
	
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

	step = vec.size() / 2;//��������� ������ ����
	while (step > 0)//���� �����������, ���� �������� ���� ������� ����
	{
		i = step;// ��������� � ��������� �������� � ������� ����
		while (i < vec.size())//��������� ����, ���� ����������� ������� ������ ������� �������
		{
			x = vec[i];//� �������� ���������� �������� �������� ������������ ��������
			j = i;//���������� ������ �������� �������� ����� ������������ ��������
			while (j >= step)//���������� �����, ���� ����� ������������ �������� ������ ���� step
			{
				if (x < vec[j - step])//���������� �������� �������������� �������� � ���������, ������������ �� ���(�� �������)
				{
					vec[j] = vec[j - step];////������ �� ����� j-�� �������� ������� � �������� j-���
					j = j - step;//��������� �������� ������� j �� �������� ����
				}
				else
					break;////������� �� ������� ��������, ���� �������� �������������� �������� ������, ��� �������� �������� ������������� �� step
			}
			vec[j] = x;//���������� �������� ������
			i++;//��������� � ��������� ��������
		}
		step /= 2;//��������� ���
	}

	auto t2 = Clock::now();

	cout << "Array after sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << vec[i] << ' ';

	cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

	system("pause");

	return 0;
}
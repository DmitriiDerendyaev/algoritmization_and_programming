#include <iostream>//����������� ����������� ���������
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;//��������� ������������ ������������ ����

typedef std::chrono::high_resolution_clock Clock;

vector<int> vec1;//���������� ����������
int n;
float k = 1.247;
int q, peremen;

int main()//������ �������� ���������
{

	cout << "Enter the amount of element:";

	cin >> q;
	for (int k = 0; k < q; k++)
	{
		peremen = rand() % q + 1;
		vec1.push_back(peremen);
	}

	cout << "Array before sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << vec1[i] << ' ';
	cout << endl << endl;

	auto t1 = Clock::now();

	n = vec1.size();//����������� ������� �������
	int step = n - 1;//������������� ������� ����(������� ����� �������)
	while (step >= 1)//������������� �������� ����� while �� �������, ���� step ������ 1
	{
		int i = 0;//������������� �������� ����������� �����
		while (i < n - step)//���������� ���� �������� ������� ������� �� ������ ������� �� �����(� ����������� ������ ������� - ���)
		{
			if (vec1[i] > vec1[i + step])//���� ������ ������� ������ �������� +step ���������� �����
				swap(vec1[i], vec1[i + step]);//���������� ����������� ��������� ������� �� ��������, �������� � �������
			i++;
		}
		step /= k;//���������� ����

	}

	auto t2 = Clock::now();

	cout << "Array after sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << vec1[i] << ' ';

	cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

	system("pause");

	return 0;
}
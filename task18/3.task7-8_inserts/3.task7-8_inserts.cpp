#include <iostream>//���������� ����������� ���������
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;//����������� ������������ ����

typedef std::chrono::high_resolution_clock Clock;

int el, buf, i, j;//���������� ����������, ����������� � ��������� �������
vector<int> vec;//��������� ������(�������)
int q, peremen;

int main()//������ �������� ���������
{
	setlocale(LC_ALL, "Russian");//��������� ������, ��������� �������� �����

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

	for (int i = 1; i < vec.size(); i++)//���������� ������� ���������� �� ������� ��������
	{
		buf = vec[i];//�������� � �������� ������ �������� �����, ������� ����� � ���������� �������������
		j = i;//���������� ���� ���������� � ������ �������������� ��������
		while (j > 0 and buf < vec[j - 1])//���� ����������� ���� ������� �� ������� �� ��� �������
			//� �� �� ������, ��� ����� �������������� �������� j � �������� �������������� �������� ������, ��� ����������
		{
			vec[j] = vec[j - 1];//���� ������� ���-���� ����������� �� �������� �������� �������
			j--;//���������� �� ������� ������ �������������� �������� ��� ����, ����� ���������� �������� ��������, �������������� ����� � ������
		}
		vec[j] = buf;//������������ �������� �������� ������ � ������ �������� ��������
	}

	auto t2 = Clock::now();

	cout << "Array after sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << vec[i] << ' ';

	cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

	system("pause");

	return 0;//���������� ���������
}
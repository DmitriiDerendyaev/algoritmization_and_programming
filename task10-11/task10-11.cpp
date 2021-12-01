#include <iostream>

using namespace std;

int main()
{
	int i, j, x, step;
	int mas[] = {6,1,5,2,3,8,20};
	
	int n = sizeof(mas) / sizeof(int);//�������� ������ ������� mas

	for (step = n / 2; step > 0; step /= 2)//������������ �������� ����, ���������� ���������� ���, ��� �������� ������� ��������� �������
	{//��������� ������ �� ��� ���, ���� ��� ������ 0
		for (i = step; i < n; i++)
		{
			x = mas[i];//���������� �������� ����������, ���� �������� �������� �������������� ��������
			for (j = i; j >= step; j -= step)//������ �������� �������� ������������� ����� �������������� ��������
			{
				if (x < mas[j - step])//���������� �������� �������������� �������� � ���������, ������������ �� ���(�� �������)
				{
					mas[j] = mas[j - step];//������ �� ����� j-�� �������� ������� � �������� j-���
				}
				else
					break;
			}
			mas[j] = x;//���� 
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
	int n2 = sizeof(mas2) / sizeof(int);//�������� ������ ������� mas
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
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;
float x1, x2, a, b, c, D;
float xx1, xx2;
float p, n;


void task1(float b, float c, float* x1, float* x2)
{
	*x1 = (-b + sqrt(pow(b, 2) - 4 * c)) / 2;
	*x2 = (-b - sqrt(pow(b, 2) - 4 * c)) / 2;
}

void task2(float a, float b, float c, float* x1, float* x2)
{
	D = pow(b, 2) - 4 * a * c;
	if (D >= 0)
	{
		*x1 = (-b + sqrt(D)) / (2*a);
		*x2 = (-b - sqrt(D)) / (2*a);
	}
	else
	{
		cout << "Error, Ignore variable values";
	}
}

int task3(float n)
{
	if (n > 0)
	{
		for (int i = 0; i < 16; i += 3)
		{
			p += 5;
		}
	}
	else
	{
		for (int j = 50; j > 0; j -= 4)
		{
			p -= 4;
		}
	}
	return p;
}


int main()
{
	int z;
	cin >> z;
	switch (z)
	{
	case 1:
	{
		cout << "B:";
		cin >> b;
		cout << "C:";
		cin >> c;
		task1(b, c, &xx1, &xx2);
		cout << "X1:" << xx1 << "; X2:" << xx2;
	}
	case 2:
	{
		cout << "A:";
		cin >> a;
		cout << "B:";
		cin >> b;
		cout << "C:";
		cin >> c;
		task2(a, b, c, &xx1, &xx2);
		cout << " X1:" << xx1 << "; X2:" << xx2;
	}
	case 3:
	{
		cout << "N:";
		cin >> n;
		cout << task3(n);
	}
	}

	return 0;
}

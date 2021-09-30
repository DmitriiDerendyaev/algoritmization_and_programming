#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;
float x1, x2, b, c;


void task1(float b, float c, float* x1, float* x2)
{
	*x1 = (-b + sqrt(pow(b, 2) - 4 * c)) / 2;
	*x2 = (-b - sqrt(pow(b, 2) - 4 * c)) / 2;
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
		float xx1, xx2;
		task1(b, c, &xx1, &xx2);
		cout << "X1:" << xx1 << "; X2:" << xx2;
	}
	}

	return 0;
}
//#include <iostream>
//#include <cmath>
//
//int main()
//{
//	float x1, x2, d, a, b, c;
//
//	std::cin >> a >> b >> c;
//
//	d = pow(b, 2) - 4 * a * c;
//
//	if d < 0 :
//}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec1;
int el, n;
float k = 1.247;


void reading(void)
{
//again:
	while (cin >> el)
	{
		vec1.push_back(el);
	}
}

void printing(void)
{
	for (int i = 0; i < vec1.size(); i++)
	{
		cout << vec1[i] << " ";
	}
	cout << endl;
}

void sort_for(void)
{
	cout << "When finished typing, press CTRL + Z:" << endl;
	reading();
	n = vec1.size();
	for (int step = n - 1; step >= 1; step /= k)
	{
		for (int i = 0; i < n - step; i++)
		{
			if (vec1[i] > vec1[i + step])
				swap(vec1[i], vec1[i + step]);
		}
	}
	printing();
}

void sort_while(void)
{
	cout << "When finished typing, press CTRL + Z:" << endl;
	reading();
	//goto again;
	n = vec1.size();
	int step = n - 1;
	while(step >= 1)
	{
		int i = 0;
		while (i < n - step)
		{
			if (vec1[i] > vec1[i + step])
				swap(vec1[i], vec1[i + step]);
			i++;
		}
		step /= k;
		
	}
	printing();
}

int main()
{
	cout << "Curren array sorted by for:" << endl;
	sort_for();
	vec1.clear();
	cout << "Curren array sorted by while:" << endl;
	sort_while();
	return 0;
}
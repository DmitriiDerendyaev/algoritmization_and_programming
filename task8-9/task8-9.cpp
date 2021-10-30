#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int el, buf, i, j;
vector<int> vec;

void reading(void)
{
	while (cin >> el)
	{
		if (el == 0)
			break;
		else
			vec.push_back(el);
		
	}
}

void printing(void)
{
	cout << vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		cout << ", " << vec[i];
	}
	cout << endl;
}

void sort_while(void)
{
	cout << "Sorting array by 'while':" << endl;
	reading();
	for (int i = 1; i < vec.size(); i++)
	{
		buf = vec[i];
		j = i;
		while (j > 0 and buf < vec[j - 1])
		{
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = buf;
	}
	printing();
}

void sort_for(void)
{
	cout << "Sorting array by 'for':" << endl;
	reading();
	for (int i = 1; i < vec.size(); i++)
	{
		for(j = i, buf = vec[i]; j > 0 and buf < vec[j - 1]; j--)
		{
			vec[j] = vec[j - 1];
		}
		vec[j] = buf;
	}
	printing();
}


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "This program sort array by 'Method vstavki'. You can enter the number of array till sign '0' or 'CTRL + Z'" << endl;
	sort_for();
	vec.clear();
	sort_while();


	return 0;
}
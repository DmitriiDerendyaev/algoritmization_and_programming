#include <iostream>
#include <vector>	
#include <ctime>
#include <iomanip>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;

int main()
{
	vector<int> array2;
	int q, peremen;
	int i, j, buf1 = 0, buf2 = 0;//îáúÿâëåíèå âñåõ ïåðåìåííûõ, âêëþ÷àÿ ïàðìåòð ìàññèâîâ, ìàññèâû, áóôåðíûå ÿ÷åéêè ïàìÿòè

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

	auto t1 = Clock::now();

	i = 0;
	j = 0;
	while (i < q - 1)
	{
		while (j < q - 1)
		{
			if (array2[j] > array2[j + 1])
			{
				buf2 = array2[j];
				array2[j] = array2[j + 1];
				array2[j + 1] = buf2;
			}
			j++;
		}
		j = 0;
		i++;
	}
	auto t2 = Clock::now();

	duration = ((double)clock() - (double)start);
	cout << "Array after sort:" << endl;
	for (int i = 0; i < q; i++)
		cout << array2[i] << ' ';

	cout << setprecision(5);
	cout << endl << "Duration(miliseconds) is: " << duration << endl;
	cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

	return 0;
}
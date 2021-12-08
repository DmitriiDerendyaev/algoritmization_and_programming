#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;

int main()
{
    int j = 2, i = 1, buf;
    vector<int> vec;
    int q, peremen;

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

    while (i < vec.size()) {//������ ����� ������� �� ����� �������
        if (vec[i - 1] > vec[i]) //�������� �������, ���� ���������� ������� ������ ��������
        {
            buf = vec[i];//���������� ����� �������� ����������� ����������� �������� ����������
            vec[i] = vec[i - 1];
            vec[i - 1] = buf;
            i--;//�.�. �� ������ � �������, ������, � ��� ��������� ������������ � ��� ����� ������, ������ �� ��� ���������� �������� � ���������� �� ��� �������, ������ ��� �����
            if (i > 0) //���� i ������ ����, ���������� �������� �����
                continue;

        }

        i = j++;//������������ ����� ����� � ������� ������������(��� ��������� ��������� ������������� �� �� �����, ������ �� ����� ������� � ������ ���������� ���������))
    }

    auto t2 = Clock::now();

    cout << "Array after sort:" << endl;
    for (int i = 0; i < q; i++)
        cout << vec[i] << ' ';

    cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

    system("pause");

    return 0;

}
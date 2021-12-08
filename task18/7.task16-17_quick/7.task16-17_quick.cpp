#include <iostream>//����������� ����������� ���������
#include <vector>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;

vector<int> vec;
int q, peremen;

void qsort(vector<int>& vec, int left, int right)//���������� ���������� ����������
{
    int i = left, j = right;//���������� ���������� �������� ������ ��������� � �������� �������� ���������
    int temp, pivot = vec[(left + right) / 2];//����� ������(����� �������� ��������)

    while (i <= j)//���� �����������, ���� ������� �� ���������
    {
        while (vec[i] < pivot) //���� �������� �������������� �������� �� ����� ����� ������ �������� �������� ��������
            i++;//�� �������� ����� ������� �� ���� ������� ������
        while (vec[j] > pivot) //���� �������� �������������� �������� �� ������ ����� ������ �������� �������� ��������
            j--;//�� �������� ������ ������� �� ���� ������� �����
        //�������� ������� � ������ - � �������� ��������
        if (i <= j)
        {
            if (vec[i] > vec[j])//���������� ������, ���� �������� �������� �������� � ����� ����� ������ �������� �������� �������� � ������ �����
            {
                temp = vec[i];//����� �������� ���������� � �������������� �������� ���������� temp
                vec[i] = vec[j];
                vec[j] = temp;
            }

            i++;
            j--;//���������� ������ ���������
        }

    }

    if (left < j)
        qsort(vec, left, j);//���� ���������� ��������� ������� � ����� �� ������, ���������� ������� ���������� ������������ �����
    if (i < right)
        qsort(vec, i, right);//���� ���������� ��������� ������� � ����� �� ������, ���������� ������� ���������� ������������ �����
}

//-------------------------------------------------------------------

int main()//������ ������� �������
{
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

    qsort(vec, 0, vec.size() - 1); // ����� ������� ����������

    auto t2 = Clock::now();

    cout << "Array after sort:" << endl;
    for (int i = 0; i < q; i++)
        cout << vec[i] << ' ';

    cout << endl << endl << "Duration(nanoseconds) is: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;

    system("pause");

    return 0;
}
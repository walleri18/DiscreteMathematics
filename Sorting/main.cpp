#include <iostream>
#include "Sorting.h"

using namespace std;

int main(void)
{
	// ������������
	setlocale(LC_ALL, ".1251");

	// ��������� ��������� ��������� ������
	vector<long> data = Sorting<long>::generationData(10);

	// ����� �� ��������������� ������
	Sorting<long>::printData(data, "�� ��������������� ������");

	// �������� ��������������� ������ � ������� ���������� ������ (Select Sort)
	vector<long> dataSortOne = Sorting<long>::selectSort(data);

	// ����� ��������������� ������ � ������� ���������� (Select Sort)
	Sorting<long>::printData(dataSortOne, "Select Sort");

	// ����������� ����������������� ������
	vector<long> dataSortTwo = data;

	// ������� ���������� (Quick Sort)
	Sorting<long>::sortQuickIn(dataSortTwo, 0, data.size() - 1);

	// ����� ��������������� ������
	Sorting<long>::printData(dataSortTwo, "Quick Sort");

	// ����� ����������, �� ��� ����������� (Bubble Sort)
	vector<long> dataSortThree = Sorting<long>::bubbleSort(data);

	// ����� ��������������� ������
	Sorting<long>::printData(dataSortThree, "Bubble Sort");

	cout << endl << endl;

	return 0;
}
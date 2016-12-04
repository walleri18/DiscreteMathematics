#include <iostream>
#include "Sorting.h"

using namespace std;

int main(void)
{
	// Руссификация
	setlocale(LC_ALL, ".1251");

	// Генерация начальный рандомных данных
	vector<long> data = Sorting<long>::generationData(10);

	// Вывод не отсортированных данных
	Sorting<long>::printData(data, "Не отсортированный массив");

	// Получаем отсортированные данные с помощью сортировки выбора (Select Sort)
	vector<long> dataSortOne = Sorting<long>::selectSort(data);

	// Вывод отсортированных данных с помощью сортировки (Select Sort)
	Sorting<long>::printData(dataSortOne, "Select Sort");

	// Копирование неотсортированных данных
	vector<long> dataSortTwo = data;

	// Быстрая сортировка (Quick Sort)
	Sorting<long>::sortQuickIn(dataSortTwo, 0, data.size() - 1);

	// Вывод отсортированных данных
	Sorting<long>::printData(dataSortTwo, "Quick Sort");

	// Снова сортировка, но уже пузырьковая (Bubble Sort)
	vector<long> dataSortThree = Sorting<long>::bubbleSort(data);

	// Вывод отсортированных данных
	Sorting<long>::printData(dataSortThree, "Bubble Sort");

	cout << endl << endl;

	return 0;
}
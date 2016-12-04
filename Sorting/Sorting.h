#pragma once
#include <vector>
#include <string>
#include <time.h>

/*
		Класс объединяющий функционал
	для генерации и сортировок данных
*/
template <typename TypeElement>
class Sorting
{
// Функционал
public:

	// Генерация случайных чисел
	static std::vector<TypeElement> generationData(long sizeArray, TypeElement zeroBegin = 0, TypeElement zeroEnd = 10)
	{
		// Зерно рандома
		srand(time(NULL));

		// Создаём пустой массив с размером sizeArray, элементы которого типа TypeElement задаваемое пользователем
		std::vector<TypeElement> data(sizeArray);

		// Заполняем массив случайными числами в диапозоне [zeroBegin; zeroEnd]
		for (long i = 0; i < sizeArray; i++)
		{
			// Генерируем случайное число из диапозона и сохраняем во временную переменную
			TypeElement tmpVar = static_cast<TypeElement>(rand() % (static_cast<long>(zeroEnd) - static_cast<long>(zeroBegin) + 1) + static_cast<long>(zeroBegin));

			// Сохраняем временную переменную в массив
			data[i] = tmpVar;
		}

		// Возвращаем массив
		return data;
	}

	// Сортировка выбора (Select Sort)
	static std::vector<TypeElement> selectSort(std::vector<TypeElement> data)
	{
		// Да начнётся сортировка выбора
		for (long i = 0; i < data.size(); i++)
		{
			// Индекс минимального элемента
			long indexMinElement = i;

			// Поиск индекса минимального элемента
			for (long j = i + 1; j < data.size(); j++)
				if (data[j] < data[indexMinElement])
					indexMinElement = j;

			// Перестановка
			swap(data[i], data[indexMinElement]);
		}

		return data;
	}

	// Быстрая сортировка Хоара возрастающая (Quick Sort)
	static void sortQuickIn(std::vector<TypeElement> &data, long begin_0, long end_0)
	{
		long l = begin_0, r = end_0;

		TypeElement piv = data[(l + r) / 2];

		while (l <= r)
		{
			while (data[l] < piv)
				l++;

			while (data[r] > piv)
				r--;

			if (l <= r)
				swap(data[l++], data[r--]);
		}

		if (begin_0 < r)
			sortQuickIn(data, begin_0, r);

		if (end_0 > l)
			sortQuickIn(data, l, end_0);
	}

	// Пузырьковая сортировка (Bubble Sort)
	static std::vector<TypeElement> bubbleSort(std::vector<TypeElement> data)
	{
		for (long i = 0; i < (data.size() - 1); i++)
		{
			// Флаг обмена
			bool swapped = false;
		    
			for (int j = 0; j < (data.size() - i - 1); j++)
			{
				if (data[j] > data[j + 1])
				{
					swap(data[j], data[j + 1]);
					
					swapped = true;
				}
			}
			
			// Если обмена не было
			if (!swapped)
				break;
		}

		return data;
	}

	// Форматированный вывод
	static void printData(std::vector<TypeElement> data, std::string message)
	{
		std::cout << std::endl << std::endl << message << ": ";

		for (long i = 0; i < data.size(); i++)
			std::cout << data[i] << " ";
	}
};
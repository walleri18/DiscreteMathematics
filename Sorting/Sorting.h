#pragma once
#include <vector>
#include <string>
#include <time.h>

/*
		����� ������������ ����������
	��� ��������� � ���������� ������
*/
template <typename TypeElement>
class Sorting
{
// ����������
public:

	// ��������� ��������� �����
	static std::vector<TypeElement> generationData(long sizeArray, TypeElement zeroBegin = 0, TypeElement zeroEnd = 10)
	{
		// ����� �������
		srand(time(NULL));

		// ������ ������ ������ � �������� sizeArray, �������� �������� ���� TypeElement ���������� �������������
		std::vector<TypeElement> data(sizeArray);

		// ��������� ������ ���������� ������� � ��������� [zeroBegin; zeroEnd]
		for (long i = 0; i < sizeArray; i++)
		{
			// ���������� ��������� ����� �� ��������� � ��������� �� ��������� ����������
			TypeElement tmpVar = static_cast<TypeElement>(rand() % (static_cast<long>(zeroEnd) - static_cast<long>(zeroBegin) + 1) + static_cast<long>(zeroBegin));

			// ��������� ��������� ���������� � ������
			data[i] = tmpVar;
		}

		// ���������� ������
		return data;
	}

	// ���������� ������ (Select Sort)
	static std::vector<TypeElement> selectSort(std::vector<TypeElement> data)
	{
		// �� ������� ���������� ������
		for (long i = 0; i < data.size(); i++)
		{
			// ������ ������������ ��������
			long indexMinElement = i;

			// ����� ������� ������������ ��������
			for (long j = i + 1; j < data.size(); j++)
				if (data[j] < data[indexMinElement])
					indexMinElement = j;

			// ������������
			swap(data[i], data[indexMinElement]);
		}

		return data;
	}

	// ������� ���������� ����� ������������ (Quick Sort)
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

	// ����������� ���������� (Bubble Sort)
	static std::vector<TypeElement> bubbleSort(std::vector<TypeElement> data)
	{
		for (long i = 0; i < (data.size() - 1); i++)
		{
			// ���� ������
			bool swapped = false;
		    
			for (int j = 0; j < (data.size() - i - 1); j++)
			{
				if (data[j] > data[j + 1])
				{
					swap(data[j], data[j + 1]);
					
					swapped = true;
				}
			}
			
			// ���� ������ �� ����
			if (!swapped)
				break;
		}

		return data;
	}

	// ��������������� �����
	static void printData(std::vector<TypeElement> data, std::string message)
	{
		std::cout << std::endl << std::endl << message << ": ";

		for (long i = 0; i < data.size(); i++)
			std::cout << data[i] << " ";
	}
};
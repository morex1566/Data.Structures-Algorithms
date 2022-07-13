#pragma once

#include <vector>

class Sort
{
public:
	static void QuickSort(std::vector<int>& vector)
	{
		sortMedianOfThree(vector.front(), vector.at(vector.size() / 2), vector.back());
		sortVectorFromTo(vector, 0, vector.size() - 1);
		
		return;
	}

private:
	Sort();
	
	static void sortMedianOfThree(int& front, int& mid, int& end)
	{
		if (front > mid)
		{
			swap(front, mid);
		}

		if (mid > end)
		{
			swap(mid, end);
		}

		if (front > mid)
		{
			swap(front, mid);
		}

		return;
	}

	static int partition(std::vector<int>& vector, int start, int end)
	{
		int pivot;
		int left;
		int right;

		pivot = (end + start) / 2;
		swap(vector[pivot], vector[end]);

		left = start;
		right = end - 1;	

		while (left < end)
		{
			if (vector[left] >= vector[end])
			{
				while (right > left)
				{
					if (vector[right] < vector[end])
					{
						swap(vector[left], vector[right]);
						break;
					}

					right--;
				}

				if (right <= left)
				{
					break;
				}
			}

			left++;
		}

		swap(vector[left], vector[end]);
		return left;
	}

	static void sortVectorFromTo(std::vector<int>& vector, int start, int end)
	{
		if (start < end)
		{
			int pivot;

			pivot = partition(vector, start, end);
			sortVectorFromTo(vector, start, pivot - 1);
			sortVectorFromTo(vector, pivot + 1, end);
		}

		return;
	}

	static void swap(int& param1, int& param2)
	{
		int temp;

		temp = param1;
		param1 = param2;
		param2 = temp;

		return;
	}
};


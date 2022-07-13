#include <iostream>
#include <vector>	
#include <string>

#include "QuickSort.h"

using namespace std;

int main()
{
	vector<int> vector;
	int			vectorSize;

	// Input the size and element of a vector.
	while (1)
	{
		int tempForSize;
		int tempForElement;

		try
		{
			cin >> tempForSize;
			if (!(1 <= tempForSize <= 1000))
			{
				throw "size error, size is limited from 1 to 1000";
			}

			for (int i = 0; i < tempForSize; i++)
			{
				cin >> tempForElement;

				if (!(-1000 <= tempForElement <= 1000))
				{
					throw "element error, element is limited from -1000 to 1000";
				}
				else
				{
					vector.push_back(tempForElement);
				}
			}
		}
		catch (string message)
		{
			cout << message << endl;
			continue;
		}

		vectorSize = tempForSize;
		break;
	}

	// Sort vector, using quicksort algorithms.
	Sort::QuickSort(vector);

	// Print vector
	for (auto& integer : vector)
	{
		cout << integer << ' ';
	}

	return 0;
}
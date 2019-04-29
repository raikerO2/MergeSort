#include <iostream>

void Merge(int A[], int low, int high, int mid)
{
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (A[i] < A[j])
		{
			c[k] = A[i];
			k++;
			i++;
		}
		else
		{
			c[k] = A[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = A[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = A[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++)
	{
		A[i] = c[i];
	}
}
void MergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int mid;
		mid = (l + r) / 2;

		MergeSort(arr, l, mid);
		MergeSort(arr, mid + 1, r);
		Merge(arr, l, r, mid);
	}

	return;
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		std::cout << " " << A[i];
	std::cout << std::endl;
}
int main()
{
	int numbers[7];
	int l = 0;
	int r = sizeof(numbers) / sizeof(numbers[0]) - 1;
	int size = sizeof(numbers) / sizeof(numbers[0]);
	int val;
	for (int i = 0; i < size; i++)
	{
		std::cout << i << ": ";
		std::cin >> val;
		numbers[i] = val;
	}
	std::cout << "Sorted: ";
	MergeSort(numbers, l, r);
	printArray(numbers, size);
	std::system("PAUSE");
}
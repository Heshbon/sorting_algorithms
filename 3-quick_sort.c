#include "sort.h"

/**
 * swap - The functions that swaps two integers in an array
 * @n: The first integer to swap
 * @m: The second integer to swap
 * Return: None
 */
void swap(int *n, int *m)
{
	int c = *n;
	*n = *m;
	*m = c;
}

/**
 * partition - The function that orders subarray and places pivot
 * using lomuto partitioning scheme
 * @array: The array of integers to be sorted
 * @size: The size of an array
 * @left: Stars the index of subarray
 * @right: Ends the index of subarray
 * Return: The partition index
 */
int partition(int *array, size_t size, int left, int right)
{
	int a = left - 1, b;

	for (b = left; b <= right - 1; b++)
	{
		if (array[b] < array[right])
		{
			a++;
			if (a != b)
			{
				swap(&array[a], &array[b]);
				print_array(array, size);
			}
		}
	}
	if (a + 1 != right)
	{
		swap(&array[a + 1], &array[right]);
		print_array(array, size);
	}
	return (a + 1);
}

/**
 * lomuto_sort - The function that implement the algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array.
 * @left: starts the index of the array
 * @right: Ends the index of the array
 * Return: None
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int j;

	if (right - left > 0)
	{
		j = partition(array, size, left, right);
		lomuto_sort(array, size, left, j - 1);
		lomuto_sort(array, size, j + 1, right);
	}
}

/**
 * quick_sort - The function that sorts an array of integers
 * in ascending order using quicksort algorithm
 * @array: Array of integers to sort
 * @size: Size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

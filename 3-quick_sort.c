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
 * lomuto_partition - The function that orders subarray and places pivot
 * using lomuto partitioning scheme
 * @array: The array of integers to be sorted
 * @low: Starts the index of subarray
 * @high: Ends the index of subarray
 * @size: The size of an array
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int piv = array[high];
	int part_index = (low - 1);
	int p;

	for (p = low; p <= high - 1; p++)
	{
		if (array[p] <= piv)
		{
			part_index++;
			if (part_index != p)
			{
				swap(&array[part_index], &array[p]);
				print_array(array, size);
			}
		}
	}
	swap(&array[part_index + 1], &array[high]);
	print_array(array, size);
	return (part_index + 1);
}

/**
 * lomuto_sort - The function that implement the algorithm
 * @array: The array of integers to be sorted
 * @low: starts the index of the array
 * @high: Ends the index of the array
 * @size: The size of the array.
 * Return: None
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int piv = lomuto_partition(array, low, high, size);

		lomuto_sort(array, low, piv - 1, size);
		lomuto_sort(array, piv + 1, high, size);
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

	lomuto_sort(array, 0, size - 1, size);
}

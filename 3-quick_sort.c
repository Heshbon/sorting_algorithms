#include "sort.h"

/**
 * partition - Function that scans a partition of
 * an array of integers for values less than
 * pivot value, and swaps them with first value in partition, then swaps pivot
 * value with first value in partition
 * @array: The array to be sorted
 * @low: The index in array that starts partition
 * @high: The index in array that ends partition
 * @size: The amount of elements in array
 * Return: The new index at which to start new recursive partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int a, b, pivot, n;

	pivot = array[high];
	a = low;
	for (b = low; b < high; b++)
	{
		if (array[b] < pivot)
		{
			n = array[a];
			array[a] = array[b];
			array[b] = n;
			if (array[a] != array[b])
				print_array(array, size);
			b++;
		}
	}
	b = array[a];
	array[a] = array[high];
	array[high] = n;
	if (array[a] != array[high])
		print_array(array, size);
	return (a);
}

/**
 * quicksort - The function that recursively sorts array of integers
 * by separating into two partitions, using Lomuto quick sort.
 * @array: The array to be sorted
 * @low: The index in array that starts partition
 * @high: The index in array that ends partition
 * @size: The amount of elements in array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int j;

	if (low < high)
	{
		j = partition(array, low, high, size);
		quicksort(array, low, j - 1, size);
		quicksort(array, j + 1, high, size);
	}
}

/**
 * quick_sort - The function that sorts an array of integers
 * in ascending order using a quicksort algorithm,
 * with Lomuto partition scheme
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}

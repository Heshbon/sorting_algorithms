#include "sort.h"

/**
 * swap - The functon that swaps two integers in an array
 * @a: First integer to swap
 * @b: Second integer to swap
 *
 * Return: None
 */
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

/**
 * lomuto_partition - The function that orders subarray
 * using lomuto partitioning scheme
 *
 * @array: Array of integers to sort
 * @size: Size of array
 * @left: Starting index of subarray
 * @right: Ending index of subarray
 *
 * Return: The partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int p = left - 1, n;

	for (n = left; n <= right - 1; n++)
	{
		if (array[n] < array[right])
		{
			p++;
			if (p != n)
			{
				swap(&array[p], &array[n]);
				print_array(array, size);
			}
		}
	}
	if (p + 1 != right)
	{
		swap(&array[p + 1], &array[right]);
		print_array(array, size);
	}
	return (p + 1);
}

/**
 * lomuto_sort - The function that implement the quicksort algorithm
 * through recursion.
 * @array: array of integers to sort.
 * @size: The size of the array.
 * @left: starting index of the array
 * @right: ending index of the array
 *
 * Return: nothing
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int b;

	if (right - left > 0)
	{
		b = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, b - 1);
		lomuto_sort(array, size, b + 1, right);
	}
}

/**
 * quick_sort - The function that sorts an array of integers
 * in ascending order using quicksort algorithm
 * @array: Array of integers to sort
 * @size: Size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

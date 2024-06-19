#include "sort.h"

/**
 * swap - The functions that swaps two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 * Return: None
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - The function that orders subarray and places pivot
 * by using lomuto partitioning scheme
 * @array: Array of integers to sort
 * @size: Size of array
 * @left: Starts the index of subarray
 * @right: Ends the index of subarray
 * Return: The partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int j = left - 1, n;

	for (n = left; n <= right - 1; n++)
	{
		if (array[n] < array[right])
		{
			j++;
			if (j != n)
			{
				swap(&array[j], &array[n]);
				print_array(array, size);
			}
		}
	}
	if (j + 1 != right)
	{
		swap(&array[j + 1], &array[right]);
		print_array(array, size);
	}
	return (j + 1);
}

/**
 * lomuto_sort - The function that implement the algorithm
 * @array: array of integers to sort.
 * @size: The size of the array.
 * @left: stars the index of the array
 * @right: Ends the index of the array
 * Return: None
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);
	}
}

/**
 * quick_sort - function that sorts an array of integers
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

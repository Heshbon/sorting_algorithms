#include "sort.h"

/**
 * selection_sort - Function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t a, p, n;
	int c;

	/* check for NULL array or array with less than 2 elements */
	if (array == NULL || size < 2)
	{
		return;
	}

	/* Iterate through the array */
	for (a = 0; a < size; a++)
	{
		/* Checks if the current index is the minimum */
		n = a;

		/* Find the minimum element in the unsorted array */
		for (p = a + 1; p < size; p++)
		{
			if (array[p] < array[n])
			{
				n = p;
			}
		}

		/* Swaps the minimum element */
		if (n != a)
		{
			c = array[a];
			array[a] = array[n];
			array[n] = c;

			/* print array after each swap */
			print_array(array, size);
		}
	}
}

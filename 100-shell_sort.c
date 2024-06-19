#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithim with the Knuth sequence.
 *
 * @array: array of integers to sort.
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, a, p;
	int n;

	if (!array || size < 2)
	{
		return;
	}

	/* Initialize the gap */
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	/* starst with the largest gap and reduces it */
	for (; gap > 0; gap /= 3)
	{
		/* performs insertion sort for the current gap */
		for (a = gap; a < size; a++)
		{
			n = array[a];

			/* shift elements to the right that are greater */
			for (p = a; p >= gap && array[p - gap] > n; p -= gap)
			{
				array[p] = array[p - gap];
			}

			array[p] = n;
		}

		/* print array */
		print_array(array, size);
	}
}

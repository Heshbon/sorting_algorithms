#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending
* order using the Bubble sort algorithm
* @array: input array of integers
* @size: size of array
*/

void bubble_sort(int *array, size_t size)
{
	size_t a;
	int temp;
	int b = -1;

	/*Array does not need to be sorted if < 2*/
	if (array == NULL || size < 2)
	{
		return;
	}

	/*loops until swap*/
	while (b)
	{
		b = 0;
		for (a = 0; a < size - 1; a++)
		{
			/*if adjacent elements not in expected order */
			if (array[a] > array[a + 1])
			{
				/*swap them */
				temp = array[a];
				array[a] = array[a + 1];
				array[a + 1] = temp;
				/*increment swap*/
				b++;

				/*print array*/
				print_array(array, size);
			}
		}
	}
}

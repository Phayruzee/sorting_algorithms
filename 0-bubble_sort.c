#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integer in ascending order
 * @array: pointer to the array data
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			/*Compare adjacent elements*/
			if (array[j] > array[j + 1])
			{
				/* Swap array[j] and array[j+1] */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}

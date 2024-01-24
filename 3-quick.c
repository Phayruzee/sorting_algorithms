#include "sort.h"
#include <stddef.h>
/**
 * lomuto_partition -  function to perform Lomuto partition
 * @array: array of integers in an unsorted array
 * @lower_bd: lower bound
 * @upper_bd: upper bound
 * @size: size of the array
 * Return: the pivot
 */

size_t lomuto_partition(int *array, size_t size, int lower_bd, int upper_bd)
{
	/*Choose the last element as the pivot*/
	int pivot = array[upper_bd];

	/*Initialize i to be one less than the lower bound */
	int i = lower_bd - 1, j, temp;

	for (j = lower_bd; j <= upper_bd - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			/*Swap elements if arr[j] <= pivot*/
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			print_array(array, size);
		}
	}
	/*Swap pivot with arr[i+1]*/
	temp = array[i + 1];
	array[i + 1] = array[upper_bd];
	array[upper_bd] = temp;
	print_array(array, size);

	/*Return the index of the pivot element*/
	return (i + 1);
}
/**
 * quick_sort_recursive - function that perform quicksort
 * @array: array of integers
 * @low: lower bound
 * @high: higher bound
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, size, low, high);
		quick_sort_recursive(array, size, low, pivot_index - 1);
		quick_sort_recursive(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}
	quick_sort_recursive(array, size, 0, size - 1);
}

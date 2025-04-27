#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array (for printing)
 *
 * Return: The final index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_recursive - Recursive quicksort using Lomuto partition
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array (for printing)
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int p = lomuto_partition(array, low, high, size);

		quicksort_recursive(array, low, p - 1, size);
		quicksort_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using the Quick sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}


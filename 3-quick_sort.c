#include "sort.h"

/**
 * swap_items - Swaps two integers in an array and prints the array.
 * @array: The array to modify.
 * @size: Total size of the array for printing.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap_items(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme.
 * @array: The array to partition.
 * @size: Total size of the array.
 * @low: Starting index of the partition.
 * @high: Ending index (pivot location).
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap_items(array, size, &array[i], &array[j]);
			i++;
		}
	}
	swap_items(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quick_sort_recursive - Recursive helper for quick_sort.
 * @array: The array to sort.
 * @size: Total size of the array.
 * @low: Starting index.
 * @high: Ending index.
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int p_idx = lomuto_partition(array, size, low, high);

		quick_sort_recursive(array, size, low, p_idx - 1);
		quick_sort_recursive(array, size, p_idx + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition).
 * @array: The array to sort.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, (int)size - 1);
}

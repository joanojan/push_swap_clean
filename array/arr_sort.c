/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:20:51 by jvila-va          #+#    #+#             */
/*   Updated: 2025/09/27 16:20:52 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	shell_sort(int *arr, int size)
{
	int	h;
	int	i;
	int	j;

	h = 1;
	while (h < size / 3)
		h = 3 * h + 1;
	while (h >= 1)
	{
		i = h;
		while (i < size)
		{
			j = i;
			while (j >= h && arr[j] < arr[j - h])
			{
				swap(&arr[j], &arr[j - h]);
				j -= h;
			}
			i++;
		}
		h = h / 3;
	}
}

int	*arr_sort(int *arr, int size)
{
	int	*sorted;

	if (size <= 1)
		return (0);
	sorted = duplicate_arr(arr, size);
	if (!sorted)
		error_exit_free(arr);
	shell_sort(sorted, size);
	return (sorted);
}

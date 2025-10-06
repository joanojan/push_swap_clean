/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:53:19 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:14:37 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/**
 *  Input string must be integer values like +1, -2, 42 ...
 * 	Duplicates are not allowed.
 * 	The stack is normalized: input [7, 8, 9] becomes [1, 2, 3]
 * 	If the input is sorted the program exits
 * 	Allowed operations to sort the stack a using helper stack b:
 * 	- pa - pb - sa - sb - ss - ra - rb - rr - rra - rrb - rrr
 */

int	has_duplicate(int value, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	*strings_to_integers(char *strings[], int size)
{
	int	*arr;
	int	value;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_exit();
	i = 0;
	while (i < size)
	{
		value = ft_atoi_arr_free(strings[i], arr);
		if (has_duplicate(value, arr, i))
			error_exit_free(arr);
		arr[i] = value;
		i++;
	}
	return (arr);
}

static void	arr_normalize(int *arr, int size)
{
	int	*arr_sorted;
	int	i;
	int	j;

	if (size <= 1)
		return ;
	arr_sorted = arr_sort(arr, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == arr_sorted[j])
			{
				arr[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	free(arr_sorted);
}

t_stack	*fill_stack(int *arr, int size)
{
	t_stack	*stack;
	t_node	*node;
	int		i;

	stack = create_stack('a');
	if (!stack)
		return (NULL);
	i = size - 1;
	while (i >= 0)
	{
		node = create_node(arr[i]);
		if (!node)
		{
			free_stack(stack);
			return (NULL);
		}
		push(node, stack);
		i--;
	}
	return (stack);
}

/**
 *  Check and normalize the input numbers.
 * 	If the input is sorted we don't need to continue.
 * 	Otherwise fill the stack and sort it.
 */

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*input_arr;
	int		size;

	if (argc < 2)
		return (0);
	size = argc -1;
	input_arr = strings_to_integers(argv + 1, size);
	if (size == 1 || arr_is_sorted(input_arr, size))
	{
		free(input_arr);
		return (0);
	}
	arr_normalize(input_arr, size);
	stack_a = fill_stack(input_arr, size);
	free(input_arr);
	if (!stack_a)
		exit (1);
	sort_stack(stack_a);
	free_stack(stack_a);
	return (0);
}

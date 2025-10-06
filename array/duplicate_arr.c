/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:21:27 by jvila-va          #+#    #+#             */
/*   Updated: 2025/09/27 16:21:28 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	*duplicate_arr(int *arr, int size)
{
	int	*copy;
	int	i;

	if (!arr || size < 1)
		return (0);
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (0);
	i = 0;
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

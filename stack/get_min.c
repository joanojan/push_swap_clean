/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:20:35 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:41:34 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *  get min initializes the indices of the nodes and
 *      keeps track of the minimal value node.
 */

t_node	*get_min(t_stack *s)
{
	t_node	*min;
	t_node	*current;
	int		pos;

	current = s->sentinel->next;
	min = current;
	pos = 0;
	while (current != s->sentinel)
	{
		current->index = ++pos;
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

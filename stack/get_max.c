/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:20:28 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:41:34 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *  get max initializes the indices of the nodes and
 *      keeps track of the maximal value node.
 */

t_node	*get_max(t_stack *s)
{
	t_node	*max;
	t_node	*current;
	int		pos;

	current = s->sentinel->next;
	max = current;
	pos = 0;
	while (current != s->sentinel)
	{
		current->index = ++pos;
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

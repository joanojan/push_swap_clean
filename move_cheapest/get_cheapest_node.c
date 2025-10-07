/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:23:40 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/07 22:42:05 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *  make sure the indices and targets are set, (needed to) compute the costs and
 *  return the node from b with minimal targe move_plan cost.
 */

t_node	*get_cheapest_node(t_stack *a, t_stack *b)
{
	t_node	*n;
	t_node	*cheap;

	if (!a || !b || a->size == 0 || b->size == 0)
		return (NULL);
	assign_indices(a);
	assign_indices(b);
	cheap = NULL;
	n = b->sentinel->next;
	while (n != b->sentinel)
	{
		set_target(n, a);
		set_node_move_plan(n, a, b);
		if (!cheap || n->move_plan.cost < cheap->move_plan.cost)
			cheap = n;
		n = n->next;
	}
	return (cheap);
}

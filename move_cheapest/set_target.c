/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:24:12 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:14:43 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *  Set the target in the node n:
 *  s will remain sorted if we insert at top of target.
 *
 */

void	set_target(t_node *n, t_stack *s)
{
	t_node	*current;
	t_node	*max;
	t_node	*min;

	if (!n || !s || s->size == 0)
		return ;
	max = get_max(s);
	min = get_min(s);
	n->target = max;
	if (n->value < min->value || n->value > max->value)
		n->target = min;
	if (n->value < max->value && n->value > min->value)
	{
		current = s->sentinel->next;
		while (current != s->sentinel)
		{
			if (current->value > n->value && current->value < n->target->value)
				n->target = current;
			current = current->next;
		}
	}
}

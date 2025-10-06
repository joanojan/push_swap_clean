/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:18:26 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:20:19 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *  reverse rotate the elements below half plus one down in the stack.
 */

static void	bring_to_top(t_stack *s, t_node *n)
{
	int	position;

	position = n->index;
	if (position < s->size / 2 + 1)
		while (n->prev != s->sentinel)
			r(s);
	else
		while (n->prev != s->sentinel)
			rrx(s);
}

/**
 *  push the two minimal values to stack b, sort the remaining 3 elements,
 *      push back to stack a.
 */
void	sort_stack_five(t_stack *a, t_stack *b)
{
	t_node	*min;

	while (a->size > 3)
	{
		min = get_min(a);
		bring_to_top(a, min);
		p(a, b);
	}
	sort_stack_three(a);
	p(b, a);
	p(b, a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_larger_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:18:31 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:18:32 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_min_to_top(t_node *min, t_stack *a)
{
	int	r_cost;
	int	rr_cost;

	if (!min || !a || a->size == 0 || min->index == 1)
		return ;
	r_cost = min->index - 1;
	rr_cost = a->size - r_cost;
	if (r_cost > rr_cost)
		while (rr_cost--)
			rrx(a);
	else
		while (r_cost--)
			r(a);
}

void	sort_stack_larger_list(t_stack *a, t_stack *b)
{
	t_node	*min;

	while (a->size > 3)
		p(a, b);
	sort_stack_three(a);
	while (b->size > 0)
		move_cheapest(a, b);
	min = get_min(a);
	bring_min_to_top(min, a);
}

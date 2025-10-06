/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:23:47 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:05:04 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Execute single-stack operations (r, rrx)
static void	execute_moves(void (*f)(t_stack *), t_stack *stack, int count)
{
	while (count-- > 0)
		f(stack);
}

// Execute dual-stack operations (rr, rrr)
static void	execute_dual_moves(void (*f)(t_stack *, t_stack *), t_stack *a,
		t_stack *b, int count)
{
	while (count-- > 0)
		f(a, b);
}

static void	execute_plan(t_node *n, t_stack *a, t_stack *b)
{
	if (n->move_plan.op == OP_RR)
	{
		execute_dual_moves(rr, a, b, n->move_plan.shared);
		execute_moves(r, a, n->move_plan.residual_a);
		execute_moves(r, b, n->move_plan.residual_b);
	}
	else if (n->move_plan.op == OP_RRR)
	{
		execute_dual_moves(rrr, a, b, n->move_plan.shared);
		execute_moves(rrx, a, n->move_plan.residual_a);
		execute_moves(rrx, b, n->move_plan.residual_b);
	}
	else if (n->move_plan.op == OP_RA_RRB)
	{
		execute_moves(r, a, n->move_plan.residual_a);
		execute_moves(rrx, b, n->move_plan.residual_b);
	}
	else
	{
		execute_moves(r, b, n->move_plan.residual_b);
		execute_moves(rrx, a, n->move_plan.residual_a);
	}
}

void	move_cheapest(t_stack *a, t_stack *b)
{
	t_node	*n;

	n = get_cheapest_node(a, b);
	if (!n)
		return ;
	execute_plan(n, a, b);
	p(b, a);
}

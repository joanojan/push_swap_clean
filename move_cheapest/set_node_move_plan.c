/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node_move_plan.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:24:05 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:14:39 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *  Calculate cost and update if cheaper.
 */

static void	try_rr_plan(int ra, int rb, t_node *n)
{
	int	cost;
	int	shared;

	cost = max(ra, rb);
	shared = min(ra, rb);
	if (cost > n->move_plan.cost)
		return ;
	n->move_plan.cost = cost;
	n->move_plan.shared = shared;
	n->move_plan.op = OP_RR;
	if (ra > shared)
		n->move_plan.residual_a = ra - shared;
	else
		n->move_plan.residual_a = 0;
	if (rb > shared)
		n->move_plan.residual_b = rb - shared;
	else
		n->move_plan.residual_b = 0;
}

static void	try_rrr_plan(int rra, int rrb, t_node *n)
{
	int	cost;
	int	shared;

	cost = max(rra, rrb);
	shared = min(rra, rrb);
	if (cost > n->move_plan.cost)
		return ;
	n->move_plan.cost = cost;
	n->move_plan.shared = shared;
	n->move_plan.op = OP_RRR;
	if (rra > shared)
		n->move_plan.residual_a = rra - shared;
	else
		n->move_plan.residual_a = 0;
	if (rrb > shared)
		n->move_plan.residual_b = rrb - shared;
	else
		n->move_plan.residual_b = 0;
}

static void	try_ra_rrb_plan(int ra, int rrb, t_node *n)
{
	int	cost;

	cost = ra + rrb;
	if (cost > n->move_plan.cost)
		return ;
	n->move_plan.cost = cost;
	n->move_plan.residual_a = ra;
	n->move_plan.residual_b = rrb;
	n->move_plan.op = OP_RA_RRB;
	n->move_plan.shared = 0;
}

static void	try_rb_rra_plan(int rb, int rra, t_node *n)
{
	int	cost;

	cost = rb + rra;
	if (cost > n->move_plan.cost)
		return ;
	n->move_plan.cost = cost;
	n->move_plan.residual_b = rb;
	n->move_plan.residual_a = rra;
	n->move_plan.op = OP_RB_RRA;
	n->move_plan.shared = 0;
}

/**
 *  Computing the possible costs to insert each node from a to b:
 *  possible operations: rr, rrr, ra + rrb, rb + rra
 */

void	set_node_move_plan(t_node *n, t_stack *a, t_stack *b)
{
	int	rb;
	int	ra;
	int	rra;
	int	rrb;

	rb = n->index - 1;
	ra = n->target->index - 1;
	if (ra == 0)
		rra = 0;
	else
		rra = a->size - ra;
	if (rb == 0)
		rrb = 0;
	else
		rrb = b->size - rb;
	reset_move_plan(n);
	try_rr_plan(ra, rb, n);
	try_rrr_plan(rra, rrb, n);
	try_ra_rrb_plan(ra, rrb, n);
	try_rb_rra_plan(rb, rra, n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:18:39 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:18:40 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_three(t_stack *stack)
{
	int	top;
	int	mid;
	int	last;

	top = stack->sentinel->next->value;
	mid = stack->sentinel->next->next->value;
	last = stack->sentinel->prev->value;
	if (top > mid && mid > last)
	{
		s(stack);
		rrx(stack);
	}
	if (top > mid && mid < last && top > last)
		r(stack);
	if (top < mid && mid > last && top > last)
		rrx(stack);
	if (top > mid && mid < last && top < last)
		s(stack);
	if (top < mid && mid > last && top < last)
	{
		rrx(stack);
		s(stack);
	}
}

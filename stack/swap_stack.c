/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:21:13 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:41:34 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Remove the first node and insert it after
 * the new first node.
 */

static void	swap_stack(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (s->size < 2)
		return ;
	first = s->sentinel->next;
	second = first->next;
	s->sentinel->next = second;
	second->prev = s->sentinel;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
}

void	s(t_stack *s)
{
	swap_stack(s);
	put_char('s');
	put_char(s->name);
	put_char('\n');
}

void	ss(t_stack *s1, t_stack *s2)
{
	swap_stack(s1);
	swap_stack(s2);
	put_str("ss\n");
}

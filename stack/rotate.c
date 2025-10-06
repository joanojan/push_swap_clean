/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:21:08 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:21:09 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Remove the first node and insert it before the sentinel.
 */

static void	rotate(t_stack *s)
{
	t_node	*first;

	if (s->size < 2)
		return ;
	first = s->sentinel->next;
	s->sentinel->next = first->next;
	first->next->prev = s->sentinel;
	first->next = s->sentinel;
	first->prev = s->sentinel->prev;
	s->sentinel->prev->next = first;
	s->sentinel->prev = first;
}

// rotate and put to stdout

void	r(t_stack *s)
{
	rotate(s);
	put_char('r');
	put_char(s->name);
	put_char('\n');
}

// rotate two stacks

void	rr(t_stack *s1, t_stack *s2)
{
	rotate(s1);
	rotate(s2);
	put_str("rr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:20:59 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:41:34 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *s)
{
	t_node	*last;

	if (s->size < 2)
		return ;
	last = s->sentinel->prev;
	s->sentinel->prev = last->prev;
	last->prev->next = s->sentinel;
	last->next = s->sentinel->next;
	last->prev = s->sentinel;
	s->sentinel->next->prev = last;
	s->sentinel->next = last;
}

void	rrx(t_stack *s)
{
	reverse_rotate(s);
	put_str("rr");
	put_char(s->name);
	put_char('\n');
}

void	rrr(t_stack *s1, t_stack *s2)
{
	reverse_rotate(s1);
	reverse_rotate(s2);
	put_str("rrr\n");
}

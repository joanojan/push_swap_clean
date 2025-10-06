/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:20:46 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:41:34 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node *n, t_stack *s)
{
	t_node	*head;
	t_node	*first;

	if (!s || !n)
		return ;
	head = s->sentinel;
	first = head->next;
	n->next = first;
	n->prev = head;
	first->prev = n;
	head->next = n;
	s->size++;
}

void	p(t_stack *src, t_stack *dst)
{
	t_node	*n;

	if (!src || !dst || src->size == 0)
		return ;
	n = pop(src);
	push(n, dst);
	put_char('p');
	put_char(dst->name);
	put_char('\n');
}

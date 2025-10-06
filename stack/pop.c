/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:20:38 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:41:34 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || s->size == 0)
		return (NULL);
	first = s->sentinel->next;
	second = first->next;
	s->sentinel->next = second;
	second->prev = s->sentinel;
	s->size--;
	first->next = NULL;
	first->prev = NULL;
	if (s->size == 0)
		s->sentinel->prev = s->sentinel;
	return (first);
}

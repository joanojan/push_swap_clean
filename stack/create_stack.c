/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:19:46 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:41:34 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*create_stack(char name)
{
	t_stack	*s;

	s = malloc(sizeof(*s));
	if (!s)
		return (NULL);
	s->sentinel = malloc(sizeof(t_node));
	if (!s->sentinel)
	{
		free(s);
		return (NULL);
	}
	s->sentinel->prev = s->sentinel;
	s->sentinel->next = s->sentinel;
	s->sentinel->index = 0;
	s->size = 0;
	s->name = name;
	return (s);
}

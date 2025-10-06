/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:18:18 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:20:15 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted_stack(t_stack *s)
{
	t_node	*n;

	n = s->sentinel->next;
	while (n->next != s->sentinel)
	{
		if (n->value > n->next->value)
			return (false);
		n = n->next;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:23:02 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:14:42 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_stack *s)
{
	int		i;
	t_node	*n;

	if (!s || s->size == 0)
		return ;
	i = 1;
	n = s->sentinel->next;
	while (n != s->sentinel)
	{
		n->index = i;
		i++;
		n = n->next;
	}
}

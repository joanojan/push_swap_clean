/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:19:51 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:41:34 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_stack(t_stack *s)
{
	t_node	*current;
	t_node	*next;

	if (!s)
		return ;
	current = s->sentinel->next;
	while (current != s->sentinel)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(s->sentinel);
	free(s);
}

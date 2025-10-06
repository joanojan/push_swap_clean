/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:18:45 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:18:46 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a)
{
	t_stack	*b;

	b = create_stack('b');
	if (!b)
		return ;
	if (a->size == 2)
		s(a);
	else if (a->size == 3)
		sort_stack_three(a);
	else if (a->size <= 5)
		sort_stack_five(a, b);
	else
		sort_stack_larger_list(a, b);
	free_stack(b);
}

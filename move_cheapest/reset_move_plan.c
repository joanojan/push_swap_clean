/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_move_plan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:23:56 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:14:46 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	reset_move_plan(t_node *n)
{
	n->move_plan = (t_move_plan){0};
	n->move_plan.cost = INT_MAX;
}

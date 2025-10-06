/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:21:18 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/06 17:38:16 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// write:
#include <unistd.h>
// exit:
#include <stdlib.h>

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_exit_free(int *a)
{
	if (a)
		free(a);
	write(2, "Error\n", 6);
	exit(1);
}

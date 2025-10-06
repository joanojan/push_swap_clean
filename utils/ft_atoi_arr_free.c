/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:21:22 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 16:43:00 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	parse_sign(const char **nptr, int *arr)
{
	int	sign;

	sign = 1;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign = -1;
		(*nptr)++;
		if (**nptr == '\0')
			error_exit_free(arr);
	}
	return (sign);
}

static long	convert_digits(const char **nptr, int sign, int *arr)
{
	long	result;

	result = 0;
	while (**nptr)
	{
		if (!ft_isdigit(**nptr))
			error_exit_free(arr);
		if (sign > 0 && result > (INT_MAX - (**nptr - '0')) / 10)
			error_exit_free(arr);
		if (sign < 0 && result > (-(long)INT_MIN - (**nptr - '0')) / 10)
			error_exit_free(arr);
		result = result * 10 + (**nptr - '0');
		(*nptr)++;
	}
	return (result);
}

int	ft_atoi_arr_free(const char *nptr, int *arr)
{
	int		sign;
	long	result;

	if (!nptr || *nptr == '\0')
		error_exit_free(arr);
	sign = parse_sign(&nptr, arr);
	result = convert_digits(&nptr, sign, arr);
	return ((int)(result * sign));
}

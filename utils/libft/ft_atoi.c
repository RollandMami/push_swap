/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:33:13 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/14 21:52:42 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static void	manage_sign(const char *str, int *i, int *sign)
{
	if (str[(*i)] == '-' || str[(*i)] == '+')
	{
		if (str[*i] == '-')
			(*sign) = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	manage_sign(nptr, &i, &sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (result > ((2147483647 - (nptr[i] - '0')) / 10))
		{
			if (sign == -1)
				return (-2147483648);
			return (2147483647);
		}
		result = result * 10 + ((int) nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

long	ft_atol(const char *nptr)
{
	int			i;
	int			sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	manage_sign(nptr, &i, &sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + ((int) nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

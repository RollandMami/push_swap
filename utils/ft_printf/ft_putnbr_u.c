/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:10:29 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/15 20:50:06 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nbr)
{
	unsigned long	n;
	int				l;

	n = (unsigned long) nbr;
	l = 0;
	if (n >= 10)
		l += ft_putnbr_u(n / 10);
	l += ft_putchar((n % 10) + '0');
	return (l);
}

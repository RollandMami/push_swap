/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:39:17 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/18 17:36:25 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

void	adaptative(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench, float disorder)
{
	int	size;

	size = stack_a->size;
	if (size <= 10 && disorder < 0.2)
		simple(stack_a, stack_b, bench);
	else if (size <= 100 && disorder < 0.5)
	{
		if (disorder <= 0.2)
			medium(stack_a, stack_b, bench, disorder);
		else
			complex(stack_a, stack_b, bench, disorder);
	}
	else
		complex(stack_a, stack_b, bench, disorder);
}
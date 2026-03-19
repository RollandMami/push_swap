/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:39:17 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 17:41:50 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"
#include "../header.h"

void	adaptative(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_bench *bench, t_strategy_info *strategy)
{
	bench->formula = "O(...)";
	if (stack_a->size <= 10 && bench->disorder < 0.2)
	{
		bench->formula = "O(n2)";
		simple(stack_a, stack_b, bench, strategy);
	}
	else if (stack_a->size <= 100 && bench->disorder < 0.5)
	{
		if (bench->disorder <= 0.2)
		{
			bench->formula = "O(n√n)";
			medium(stack_a, stack_b, bench, strategy);
		}
		else
		{
			bench->formula = "O(nlogn)";
			complex(stack_a, stack_b, bench, strategy);
		}
	}
	else
	{
		bench->formula = "O(nlogn)";
		complex(stack_a, stack_b, bench, strategy);
	}
}

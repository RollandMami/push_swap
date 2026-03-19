/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:38:19 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 16:45:05 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

void	simple(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench,
			t_strategy_info *strategy)
{
	t_stack	*min;
	int		pos;

	if (!stack_a || !stack_a->head)
		return ;
	while (stack_a->size > 3)
	{
		min = get_min(stack_a);
		pos = get_position(stack_a, min);
		if (pos <= stack_a->size / 2)
		{
			while (stack_a->head != min)
				ra(stack_a, bench, 0, strategy->bench_bool);
		}
		else
		{
			while (stack_a->head != min)
				rra(stack_a, bench, 0, strategy->bench_bool);
		}
		pb(stack_a, stack_b, bench, strategy->bench_bool);
	}
	three_args(stack_a, bench, strategy);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, bench, strategy->bench_bool);
}

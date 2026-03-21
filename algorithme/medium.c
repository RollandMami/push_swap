/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:38:12 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/21 07:22:06 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

static int	get_chunk(int size, float disorder)
{
	int	chunk;

	if (size <= 100)
		chunk = 15;
	else if (size <= 500)
		chunk = 35;
	else
		chunk = size / 15;
	if (disorder < 0.2)
		chunk += 10;
	else if (disorder < 0.5)
		chunk += 5;
	return (chunk);
}

static void	push_back(t_stack_ctrl *a, t_stack_ctrl *b,
			t_bench *bench, t_strategy_info *strategy)
{
	t_stack	*target;
	int		pos;
	int		index;

	while (b->size > 0)
	{
		index = b->size -1;
		target = find_by_index(b, index);
		pos = get_position(b, target);
		while (b->head != target)
		{
			if (b->head->index == index - 1)
			{
				pa(a, b, bench, strategy->bench_bool);
				index--;
			}
			else if (pos > b->size / 2)
				rrb(b, bench, 0, strategy->bench_bool);
			else
				rb(b, bench, 0, strategy->bench_bool);
		}
		pa(a, b, bench, strategy->bench_bool);
		if (a->size > 1 && a->head->index > a->head->next->index)
			sa(a, bench, 0, strategy->bench_bool);
	}
}

void	medium(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_bench *bench, t_strategy_info *strategy)
{
	int	i;
	int	range;

	range = get_chunk(stack_a->size, bench->disorder);
	i = 0;
	while (stack_a->size > 0)
	{
		if (stack_a->head->index <= i)
		{
			pb(stack_a, stack_b, bench, strategy->bench_bool);
			rb(stack_b, bench, 0, strategy->bench_bool);
			i++;
		}
		else if (stack_a->head->index <= i + range)
		{
			pb(stack_a, stack_b, bench, strategy->bench_bool);
			i++;
		}
		else
			ra(stack_a, bench, 0, strategy->bench_bool);
	}
	push_back(stack_a, stack_b, bench, strategy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:38:25 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/22 21:17:42 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

void	quick_sort_a(t_stack_ctrl *a, t_stack_ctrl *b,
			t_bench *bn, t_strategy_info *st)
{
	int	pivot;
	int	items[2];
	int	i;

	items[2] = {0, 0};
	if (is_sorted_block(a, a->size))
		return ;
	if (a->size <= 3)
	{
		if (a->size == 2 && a->head->index > a->head->next->index)
			sa(a, bn, 0, st->bench_bool);
		else if (a->size == 3)
			sort_three_a(a, b, bn, st);
		return ;
	}
	pivot = get_median(a, a->size);
	i = 0;
	while (i < a->size)
	{
		if (a->head->index < pivot)
			items[0] += (pb(a, b, bn, st->bench_bool), 1);
		else
			items[1] += (ra(a, bn, 0, st->bench_bool), 1);
		i++;
	}
	if (items[1] != a->size)
	{
		i = 0;
		while (i < items[1])
		{
			rra(a, bn, 0, st->bench_bool);
			i++;
		}
	}
	quick_sort_a(a, b, items[1], bn, st);
	quick_sort_b(a, b, items[0], bn, st);
}

void	quick_sort_b(t_stack_ctrl *a, t_stack_ctrl *b,
			t_bench *bn, t_strategy_info *st)
{
	int	pivot;
	int	items[2];
	int	i;

	items[2] = {0, 0};
	if (is_rev_sorted_block(b, b->size))
	{
		while (b->size)
			pa(a, b, bn, st->bench_bool);
		return ;
	}
	if (b->size <= 3)
	{
		while (b->size)
		{
			if (b->size > 1 && b->head->index < b->head->next->index)
				sb(b, bn, 0, st->bench_bool);
			pa(a, b, bn, st->bench_bool);
			if (a->size > 1 && a->head->index > a->head->next->index)
				sa(a, bn, 0, st->bench_bool);
		}
		return ;
	}
	pivot = get_median(b, b->size);
	i = 0;
	while (i < b->size)
	{
		if (b->head->index >= pivot)
			items[0] += (pa(a, b, bn, st->bench_bool), 1);
		else
			items[1] += (rb(b, bn, 0, st->bench_bool), 1);
		i++;
	}
	quick_sort_a(a, b, items[0], bn, st);
	if (items[1] != b->size)
	{
		i = 0;
		while (i < items[1])
		{
			rrb(b, bn, 0, st->bench_bool);
			i++;
		}
	}
	quick_sort_b(a, b, items[1], bn, st);
}

void	complex(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_bench *bench, t_strategy_info *strategy)
{
	if (is_sorted(stack_a))
		return ;
	quick_sort_a(stack_a, stack_b, stack_a->size, bench, strategy);
}

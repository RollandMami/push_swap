/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewer_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:38:03 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 18:03:51 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

void	two_args(t_stack_ctrl *stack_a, t_bench *bench, t_strategy_info *strat)
{
	if (stack_a->head->content > stack_a->head->next->content)
		sa(stack_a, bench, 0, strat->bench_bool);
}

void	three_args(t_stack_ctrl *stack_a, t_bench *bench,
			t_strategy_info *strat)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->content;
	second = stack_a->head->next->content;
	third = stack_a->head->next->next->content;
	if (first > second && second < third && first < third)
		sa(stack_a, bench, 0, strat->bench_bool);
	else if (first > second && second > third)
	{
		sa(stack_a, bench, 0, strat->bench_bool);
		rra(stack_a, bench, 0, strat->bench_bool);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, bench, 0, strat->bench_bool);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, bench, 0, strat->bench_bool);
		ra(stack_a, bench, 0, strat->bench_bool);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, bench, 0, strat->bench_bool);
}

int	is_circular_sorted(t_stack_ctrl *stack)
{
	t_stack	*current;
	int		count;

	if (!stack || !stack->head || stack->size < 2)
		return (1);
	count = 0;
	current = stack->head;
	while (current->next)
	{
		if (current->content > current->next->content)
			count++;
		current = current->next;
	}
	if (current->content > stack->head->content)
		count++;
	return (count <= 1);
}

void	five_args_optimisation(t_stack_ctrl *stack_a, t_bench *bench,
			t_strategy_info *strat)
{
	t_stack	*min;
	int		pos;

	if (is_circular_sorted(stack_a))
	{
		min = get_min(stack_a);
		pos = get_position(stack_a, min);
		while (!is_sorted(stack_a))
		{
			if (pos <= stack_a->size / 2)
				ra(stack_a, bench, 0, strat->bench_bool);
			else
				rra(stack_a, bench, 0, strat->bench_bool);
		}
		return ;
	}
}

void	five_args(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench,
			t_strategy_info *strat)
{
	t_stack	*min;
	int		pos;

	five_args_optimisation(stack_a, bench, strat);
	if (is_sorted(stack_a))
		return ;
	while (stack_a->size > 3)
	{
		min = get_min(stack_a);
		pos = get_position(stack_a, min);
		if (pos <= stack_a->size / 2)
		{
			while (stack_a->head != min)
				ra(stack_a, bench, 0, strat->bench_bool);
		}
		else
		{
			while (stack_a->head != min)
				rra(stack_a, bench, 0, strat->bench_bool);
		}
		pb(stack_a, stack_b, bench, strat->bench_bool);
	}
	three_args(stack_a, bench, strat);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, bench, strat->bench_bool);
}

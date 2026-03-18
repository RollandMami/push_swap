/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewer_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:38:03 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/18 07:38:03 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

void	two_args(t_stack_ctrl *stack_a, t_bench *bench)
{
	if (stack_a->head->content > stack_a->head->next->content)
		sa(stack_a, bench, 0);
}

void	three_args(t_stack_ctrl *stack_a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->content;
	second = stack_a->head->next->content;
	third = stack_a->head->next->next->content;
	if (first > second && second < third && first < third)
		sa(stack_a, bench, 0);
	else if (first > second && second > third)
	{
		sa(stack_a, bench, 0);
		rra(stack_a, bench, 0);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, bench, 0);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, bench, 0);
		ra(stack_a, bench, 0);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, bench, 0);
}

void	five_args(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench)
{
	t_stack	*min;
	int		pos;

	while (stack_a->size > 3)
	{
		min = get_min(stack_a);
		pos = get_position(stack_a, min);
		if (pos <= stack_a->size / 2)
		{
			while (stack_a->head != min)
				ra(stack_a, bench, 0);
		}
		else
		{
			while (stack_a->head != min)
				rra(stack_a, bench, 0);
		}
		pb(stack_a, stack_b, bench);
	}
	three_args(stack_a, bench);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, bench);
}

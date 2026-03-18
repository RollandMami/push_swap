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
	while (stack_a->size > 3)
	{
		if (stack_a->head->content == stack_a->size - 1
			|| stack_a->head->content == stack_a->size - 2)
			pb(stack_a, stack_b, bench);
		else
			ra(stack_a, bench, 0);
	}
	three_args(stack_a, bench);
	if (stack_b->head->content < stack_b->head->next->content)
		sb(stack_b, bench, 0);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, bench);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:44:48 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 18:03:32 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	manage_strategy(t_strategy_info *flags, t_stack_ctrl *stack_a,
			t_stack_ctrl *stack_b, t_bench *bench)
{
	char	*strat;

	if (!flags || !stack_a || !bench)
		return ;
	if (is_sorted(stack_a))
		return ;
	if (!flags || flags->size == 0 || !flags->last)
	{
		adaptative(stack_a, stack_b, bench, flags);
		return ;
	}
	strat = flags->last->content;
	if (ft_strcmp(strat, "--simple") == 0)
		simple(stack_a, stack_b, bench, flags);
	else if (ft_strcmp(strat, "--medium") == 0)
		medium(stack_a, stack_b, bench, flags);
	else if (ft_strcmp(strat, "--complex") == 0)
		complex(stack_a, stack_b, bench, flags);
	else
		adaptative(stack_a, stack_b, bench, flags);
}

void	push_swap(t_strategy_info *flags, t_stack_ctrl *stack_a,
			t_bench *bench)
{
	t_stack_ctrl	stack_b;

	ft_memset(&stack_b, 0, sizeof(t_stack_ctrl));
	if (bench->disorder == 0)
	{
		free_stack(&stack_b);
		return ;
	}
	else if (stack_a->size == 2)
	{
		two_args(stack_a, bench, flags);
		bench->formula = "O(n2)";
	}
	else if (stack_a->size <= 3)
	{
		three_args(stack_a, bench, flags);
		bench->formula = "O(n2)";
	}
	else if (stack_a->size <= 5)
	{
		five_args(stack_a, &stack_b, bench, flags);
		bench->formula = "O(n2)";
	}
	else
		manage_strategy(flags, stack_a, &stack_b, bench);
}

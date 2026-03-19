/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:38:23 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/18 17:39:29 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_strategy(t_strategy_info *strategy)
{
	t_strategy	*current;
	t_strategy	*temp;

	if (!strategy || !strategy->head)
		return ;
	current = strategy->head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	strategy->bench_bool = 0;
	strategy->head = NULL;
	strategy->last = NULL;
	strategy->size = 0;
}

void	free_stack(t_stack_ctrl *stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack || !stack->head)
		return ;
	current = stack->head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	stack->head = NULL;
	stack->last = NULL;
	stack->size = 0;
}

void	free_bench(t_bench *bench)
{
	if (!bench)
		return ;
	bench->total = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->disorder = 0;
	bench->formula = NULL;
}

void	error_exit(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_strategy_info *flags, t_bench *bench)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (flags)
		free_strategy(flags);
	if (bench)
		free_bench(bench);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_all(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_strategy_info *flags, t_bench *bench)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (flags)
		free_strategy(flags);
	if (bench)
		free_bench(bench);
}

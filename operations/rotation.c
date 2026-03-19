/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:50:20 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 18:06:36 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rotation(t_stack_ctrl *stack)
{
	t_stack	*old_head;
	t_stack	*new_head;

	if (!stack || !stack->head || stack->size < 2)
		return ;
	old_head = stack->head;
	new_head = old_head->next;
	new_head->prev = NULL;
	stack->head = new_head;
	old_head->next = NULL;
	old_head->prev = stack->last;
	stack->last->next = old_head;
	stack->last = old_head;
}

void	ra(t_stack_ctrl *stack_a, t_bench *bench, int is_rr, int is_bench)
{
	rotation(stack_a);
	if (!is_rr)
	{
		if (bench)
		{
			bench->ra++;
			bench->total++;
		}
		if (!is_bench)
			ft_printf("ra\n");
	}
}

void	rb(t_stack_ctrl *stack_b, t_bench *bench, int is_rr, int is_bench)
{
	rotation(stack_b);
	if (!is_rr)
	{
		if (!is_bench)
			ft_printf("rb\n");
		if (bench)
		{
			bench->rb++;
			bench->total++;
		}
	}
}

void	rr(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench,
			int is_bench)
{
	ra(stack_a, bench, 1, is_bench);
	rb(stack_b, bench, 1, is_bench);
	if (!is_bench)
		ft_printf("rr\n");
	if (bench)
	{
		bench->rr++;
		bench->total++;
	}
}

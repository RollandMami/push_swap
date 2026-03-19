/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:08:32 by rolland           #+#    #+#             */
/*   Updated: 2026/03/19 16:23:29 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	swap(t_stack_ctrl *stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*reste;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	reste = second->next;
	first->next = reste;
	if (reste)
		reste->prev = first;
	else
		stack->last = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	stack->head = second;
}

void	sa(t_stack_ctrl *stack_a, t_bench *bench, int is_ss, int is_bench)
{
	if (stack_a->size <= 1)
		return ;
	swap(stack_a);
	if (!is_ss)
	{
		if (bench)
		{
			bench->sa++;
			bench->total++;
		}
		if (!is_bench)
			ft_printf("sa\n");
	}
}

void	sb(t_stack_ctrl *stack_b, t_bench *bench, int is_ss, int is_bench)
{
	if (stack_b->size <= 1)
		return ;
	swap(stack_b);
	if (!is_ss)
	{
		if (bench)
		{
			bench->sb++;
			bench->total++;
		}
		if (!is_bench)
			ft_printf("sb\n");
	}
}

void	ss(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench,
			int is_bench)
{
	if (!((stack_a && stack_a->size > 1)
			|| (stack_b && stack_b->size > 1)))
		return ;
	sa(stack_a, bench, 1, is_bench);
	sb(stack_b, bench, 1, is_bench);
	if (bench)
	{
		bench->ss++;
		bench->total++;
	}
	if (!is_bench)
		ft_printf("ss\n");
}

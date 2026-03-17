/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:50:20 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/17 15:47:00 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	r_rotation(t_stack_ctrl *stack)
{
	t_stack	*new_head;
	t_stack	*new_last;

	if (!stack || !stack->head || stack->size < 2)
		return ;
	new_head = stack->last;
	new_last = new_head->prev;
	if (!new_last)
		return ;
	new_head->prev = NULL;
	new_head->next = stack->head;
	stack->head->prev = new_head;
	stack->head = new_head;
	new_last->next = NULL;
	stack->last = new_last;
}

void	rra(t_stack_ctrl *stack_a, t_bench *bench, int is_rrr)
{
	r_rotation(stack_a);
	if (!is_rrr)
	{
		ft_printf("rra\n");
		if (bench)
		{
			bench->rra++;
			bench->total++;
		}
	}
}

void	rrb(t_stack_ctrl *stack_b, t_bench *bench, int is_rrr)
{
	r_rotation(stack_b);
	if (!is_rrr)
	{
		ft_printf("rrb\n");
		if (bench)
		{
			bench->rrb++;
			bench->total++;
		}
	}
}

void	rrr(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench)
{
	rra(stack_a, bench, 1);
	rrb(stack_b, bench, 1);
	ft_printf("rrr\n");
	if (bench)
	{
		bench->rrr++;
		bench->total++;
	}
}

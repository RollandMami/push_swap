/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:50:20 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 16:16:41 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	push(t_stack_ctrl *from, t_stack_ctrl *to)
{
	t_stack	*moved_node;

	if (!from || !from->head)
		return ;
	moved_node = from->head;
	from->head = moved_node->next;
	if (from->head)
		from->head->prev = NULL;
	else
		from->last = NULL;
	from->size--;
	moved_node->next = to->head;
	if (to->head)
		to->head->prev = moved_node;
	else
		to->last = moved_node;
	to->head = moved_node;
	to->size++;
}

void	pa(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench, int is_bench)
{
	if (!stack_b || !stack_b->head)
		return ;
	push(stack_b, stack_a);
	if (bench)
	{
		bench->pa++;
		bench->total++;
	}
	if (!is_bench)
		ft_printf("pa\n");
}

void	pb(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench, int is_bench)
{
	if (!stack_a || !stack_a->head)
		return ;
	push(stack_a, stack_b);
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
	if (!is_bench)
		ft_printf("pb\n");
}

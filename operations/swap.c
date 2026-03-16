/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:08:32 by rolland           #+#    #+#             */
/*   Updated: 2026/03/15 21:29:28 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void    swap(t_stack_ctrl *stack)
{
    t_stack *first;
    t_stack *second;

    if (!stack || !stack->head || !stack->head->next)
        return ;
    
    first = stack->head;
    second = first->next;
    
    first->next = second->next;
    second->next = first;
    stack->head = second;
    
    if (stack->size == 2)
        stack->last = first;
}

void    sa(t_stack_ctrl *stack_a, t_bench *bench, int is_ss)
{
    swap(stack_a);
    if (!is_ss)
    {
        if (bench)
        {
            bench->sa++;
            bench->total++;
        }
        ft_printf("sa\n");
    }
}
void    sb(t_stack_ctrl *stack_b, t_bench *bench, int is_ss)
{
    swap(stack_b);
    if (!is_ss)
    {
        if (bench)
        {
            bench->sb++;
            bench->total++;
        }
        ft_printf("sb\n");
    }
}

void    ss(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench)
{
    sa(stack_a, bench, 1);
    sb(stack_b, bench, 1);
    
    if (bench)
    {
        bench->ss++;
        bench->total++;
    }
    ft_printf("ss\n");
}
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

void    sa(t_stack_ctrl *stack_a, t_bench *bench)
{
    t_stack *first;
    t_stack *second;

    if (!stack_a || !stack_a->head || !stack_a->head->next)
        return ;
    
    first = stack_a->head;
    second = first->next;
    
    first->next = second->next;
    second->next = first;
    stack_a->head = second;
    
    if (stack_a->size == 2)
        stack_a->last = first;
    
    if (bench)
    {
        bench->sa++;
        bench->total++;
    }
    ft_printf("sa\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:50:20 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/15 21:11:55 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void    rotation(t_stack_ctrl *stack)
{
    t_stack *first;
    t_stack *second;

    if (!stack || !stack->head || stack->size < 2)
        return ;
    
    first = stack->head;
    second = first->next;
    stack->head = second;
    stack->last->next = first;
    stack->last = first;    
    stack->last->next = NULL;
}

void    ra(t_stack_ctrl *stack_a, t_bench *bench, int is_rr)
{
    rotation(stack_a);
    if (!is_rr)
    {
        ft_printf("ra\n");
        bench->ra++;
    }
}

void    rb(t_stack_ctrl *stack_b, t_bench *bench, int is_rr)
{
    rotation(stack_b);
    if (!is_rr)
    {
        ft_printf("rb\n");
        bench->rb++;
    }
}

void    rr(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench)
{
    rotation(stack_a);
    rotation(stack_b);
    ft_printf("rr\n");
    if(bench)
    {
        bench->rr++;
        bench->total++;
    }
}
void    r_rotation(t_stack_ctrl *stack)
{
    t_stack *old_last;
}
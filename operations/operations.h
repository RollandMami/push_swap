/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:50:20 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/18 17:35:41 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../header.h"

void	swap(t_stack_ctrl *stack);
void	sa(t_stack_ctrl *stack_a, t_bench *bench, int is_ss);
void	sb(t_stack_ctrl *stack_b, t_bench *bench, int is_ss);
void	ss(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench);
void	rr(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench);
void	rb(t_stack_ctrl *stack_b, t_bench *bench, int is_rr);
void	ra(t_stack_ctrl *stack_a, t_bench *bench, int is_rr);
void	rotation(t_stack_ctrl *stack);
void	r_rotation(t_stack_ctrl *stack);
void	push(t_stack_ctrl *from, t_stack_ctrl *to);
void	pa(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench);
void	pb(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench);
void	rra(t_stack_ctrl *stack_a, t_bench *bench, int is_rrr);
void	rrb(t_stack_ctrl *stack_b, t_bench *bench, int is_rrr);
void	rrr(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench);

#endif

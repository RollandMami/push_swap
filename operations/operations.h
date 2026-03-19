/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:50:20 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 16:23:07 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../header.h"
# include "../utils/struct.h"

void	swap(t_stack_ctrl *stack);
void	sa(t_stack_ctrl *stack_a, t_bench *bench, int is_ss, int is_bench);
void	sb(t_stack_ctrl *stack_b, t_bench *bench, int is_ss, int is_bench);
void	ss(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench,
			int is_bench);
void	rr(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench,
			int is_bench);
void	rb(t_stack_ctrl *stack_b, t_bench *bench, int is_rr, int is_bench);
void	ra(t_stack_ctrl *stack_a, t_bench *bench, int is_rr, int is_bench);
void	rotation(t_stack_ctrl *stack);
void	r_rotation(t_stack_ctrl *stack);
void	push(t_stack_ctrl *from, t_stack_ctrl *to);
void	pa(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench,
			int is_bench);
void	pb(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench,
			int is_bench);
void	rra(t_stack_ctrl *stack_a, t_bench *bench, int is_rrr, int is_bench);
void	rrb(t_stack_ctrl *stack_b, t_bench *bench, int is_rrr, int is_bench);
void	rrr(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench,
			int is_bench);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:12:37 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/17 21:37:51 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHME_H
# define ALGORITHME_H

# include "../header.h"

void	adaptative(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench, float disorder);
void	two_args(t_stack_ctrl *stack_a, t_bench *bench);
void	three_args(t_stack_ctrl *stack_a, t_bench *bench);
void	five_args(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench);
void	simple(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench);
void	medium(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench, float disorder);
void	complex(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench, float disorder);
int		is_sorted(t_stack_ctrl *stack);
t_stack	*get_min(t_stack_ctrl *stack);
int		get_position(t_stack_ctrl *stack, t_stack *min);

#endif

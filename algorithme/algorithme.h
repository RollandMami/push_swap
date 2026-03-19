/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:12:37 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 18:05:18 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHME_H
# define ALGORITHME_H

# include "../header.h"

void	adaptative(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_bench *bench, t_strategy_info *strat);
void	two_args(t_stack_ctrl *stack_a, t_bench *bench, t_strategy_info *strat);
void	three_args(t_stack_ctrl *stack_a, t_bench *bench,
			t_strategy_info *strat);
void	five_args(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench,
			t_strategy_info *strat);
void	simple(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_bench *bench, t_strategy_info *strategy);
void	medium(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_bench *bench, t_strategy_info *strategy);
void	complex(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_bench *bench, t_strategy_info *strategy);
int		is_sorted(t_stack_ctrl *stack);
t_stack	*get_min(t_stack_ctrl *stack);
int		get_position(t_stack_ctrl *stack, t_stack *min);
int		is_circular_sorted(t_stack_ctrl *stack);
void	five_args_optimisation(t_stack_ctrl *stack_a, t_bench *bench,
			t_strategy_info *strat);

#endif

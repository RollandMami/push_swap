/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:12:37 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/21 18:12:07 by mamiandr         ###   ########.fr       */
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
void	quick_sort(int	*tableau, int bas, int haut);
int		tab_partition(int *tableau, int bas, int haut);
void	insertion_sort(int	*tableau, int size);
void	prepare_stack(t_stack_ctrl *stack, t_bench *bench);
void	sort_three_a(t_stack_ctrl *a, t_stack_ctrl *b, t_bench *bn,
		t_strategy_info *st);
void	quick_sort_a(t_stack_ctrl *a, t_stack_ctrl *b, int len, t_bench *bn, t_strategy_info *st);
void	quick_sort_b(t_stack_ctrl *a, t_stack_ctrl *b, int len, t_bench *bn, t_strategy_info *st);
void	complex(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
            t_bench *bench, t_strategy_info *strategy);
int		get_median(t_stack_ctrl *stack, int len);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:12:37 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 15:55:07 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"
# include "../parsing/parsing.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

int		ft_strcmp(const char *s1, const char*s2);
float	compute_disorder(t_stack *stack_a);
void	free_stack(t_stack_ctrl *stack);
void	free_strategy(t_strategy_info *strategy);
void	add_strategy(t_strategy_info *strategy, char *argv);
void	fill_stack(char *str, t_stack_ctrl *stack);
char	*get_strategy_name(t_strategy_info *flag);
void	print_bench(t_strategy_info *strategy, t_bench *bench);
char	*get_formula(char *strategy);
void	free_bench(t_bench *bench);
void	error_exit(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_strategy_info *flags, t_bench *bench);
void	free_all(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_strategy_info *flags, t_bench *bench);

#endif

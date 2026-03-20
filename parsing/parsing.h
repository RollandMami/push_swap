/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:49:18 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/20 22:02:42 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../utils/utils.h"

void	check_duplicate(t_stack_ctrl *stack);
void	check_flags(int argc, char **argv,
			t_strategy_info *flag_list, t_stack_ctrl *stack);
char	**normalize_argv(int argc, char **argv);
int		get_position(t_stack_ctrl *stack, t_stack *min);
t_stack	*get_min(t_stack_ctrl *stack);
int		is_sorted(t_stack_ctrl *stack);
int		is_number(char *str);
int		*stack_to_array(t_stack_ctrl *stack);
void	index_stack(t_stack_ctrl *stack, int *array);
t_stack	*find_by_index(t_stack_ctrl *stack, int index);
int		*stack_to_array(t_stack_ctrl *stack);
int		index_binary_srch(int value, int *tab, int size);

#endif

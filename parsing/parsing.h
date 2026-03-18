/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:49:18 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/15 21:12:37 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../header.h"

void	check_duplicate(t_stack *stack);
void	check_flags(int argc, char **argv,
			t_strategy_info *flag_list, t_stack_ctrl *stack);
char	**normalize_argv(int argc, char **argv);
int		get_position(t_stack_ctrl *stack, t_stack *min);
t_stack	*get_min(t_stack_ctrl *stack);
int 	is_sorted(t_stack_ctrl *stack);

#endif

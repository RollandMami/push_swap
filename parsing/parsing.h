/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:49:18 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/14 19:55:53 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../header.h"

int		    check_duplicate(t_stack *stack);
void		check_flags(int argc, char **argv,t_strategy_info *flag_list, t_stack_ctrl **stack);
int	    	check_bench_flag(int argc, char **argv);
char    	**normalize_argv(int argc, char **argv);
//void	fill_stack(int argc, char **argv, t_list **data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:49:18 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/13 12:56:42 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../header.h"

int		check_duplicate(int argc, char **argv);
int		check_flags(int argc, char **argv,t_list **flag_list);
int		check_bench_flag(int argc, char **argv);
char	**normalize_argv(int argc, char **argv);
//void	fill_stack(int argc, char **argv, t_list **data);

#endif

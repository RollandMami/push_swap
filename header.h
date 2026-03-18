/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:49:24 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/18 17:44:34 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

# include "./utils/utils.h"
# include "./parsing/parsing.h"
# include "./operations/operations.h"
# include "./algorithme/algorithme.h"

void    push_swap(t_strategy_info *flags, t_stack_ctrl *stack_a, t_bench *bench, float disorder);
void    manage_strategy(t_strategy_info *flags, t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench, float disorder);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:50:20 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/15 21:11:55 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../header.h"

void    swap(t_stack_ctrl *stack);
void    sa(t_stack_ctrl *stack_a, t_bench *bench, int is_ss);
void    sb(t_stack_ctrl *stack_b, t_bench *bench, int is_ss);
void    ss(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b, t_bench *bench);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:52:54 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 16:55:13 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_bench
{
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		total;
	float	disorder;
	char	*formula;
}			t_bench;

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stack_ctrl
{
	struct s_stack	*head;
	struct s_stack	*last;
	int				size;
}				t_stack_ctrl;

typedef struct s_strategy
{
	char				*content;
	struct s_strategy	*next;
}				t_strategy;

typedef struct s_strategy_info
{
	struct s_strategy	*head;
	struct s_strategy	*last;
	int					bench_bool;
	int					size;
}				t_strategy_info;


#endif

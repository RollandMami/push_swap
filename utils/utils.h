/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:12:37 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/15 20:39:18 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_bench
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	disorder;
	int	total;
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

int		ft_strcmp(const char *s1, const char*s2);
float	compute_disorder(t_stack *stack_a);
void	add_strategy(t_strategy_info *strategy, char *argv);
void	fill_stack(char *str, t_stack_ctrl *stack);

#endif

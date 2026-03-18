/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:12:37 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/18 21:50:26 by mamiandr         ###   ########.fr       */
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
	float	disorder;
	int	total;
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

int		ft_strcmp(const char *s1, const char*s2);
float	compute_disorder(t_stack *stack_a);
void	free_stack(t_stack_ctrl *stack);
void	free_strategy(t_strategy_info *strategy);
void	add_strategy(t_strategy_info *strategy, char *argv);
void	fill_stack(char *str, t_stack_ctrl *stack);
char	*get_strategy_name(t_strategy_info *flag);
void	print_bench(t_strategy_info *strategy,t_bench *bench);
char	*get_formula(char *strategy);

#endif

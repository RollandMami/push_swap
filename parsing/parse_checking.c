/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:41:35 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/15 21:02:31 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_valid_flag(char *str)
{
	int	res;

	res = 0;
	if (ft_strcmp(str, "--simple") == 0)
		res = 1;
	if (ft_strcmp(str, "--medium") == 0)
		res = 1;
	if (ft_strcmp(str, "--complex") == 0)
		res = 1;
	if (ft_strcmp(str, "--adaptative") == 0)
		res = 1;
	if (ft_strcmp(str, "--bench") == 0)
		res = 1;
	return (res);
}

void	check_duplicate(t_stack *stack)
{
	t_stack	*runner;
	t_stack *current;

	current = stack;
	while(current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content == runner->content)
			{
				ft_printf("Error : [argument duplications]");
				return ;
			}

			runner = runner->next;
		}
		current = current->next;
	}
}


static int is_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void check_flags(int argc, char **argv,t_strategy_info *flag_list, t_stack_ctrl *stack)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
		{
			if (is_valid_flag(argv[i]) == 0)
			{
				ft_printf("Error : [flag incorrect]");
				return ;
			}
			if (ft_strcmp(argv[i], "--bench") == 0)
				flag_list->bench_bool = 1;
			else
				add_strategy(flag_list, argv[i]);
		}
		else
		{
			if (!is_number(argv[i]) && !ft_strchr(argv[i], ' '))
			{
				ft_printf("Error : [argument incorrect]");
				return ;
			}
			fill_stack(argv[i], stack);
		}
		i++;
	}
}



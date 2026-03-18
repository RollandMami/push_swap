/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:41:35 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/18 21:27:21 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_valid_flag(char *str)
{
	if (!ft_strcmp(str, "--simple") || !ft_strcmp(str, "--medium")
		|| !ft_strcmp(str, "--complex") || !ft_strcmp(str, "--adaptative")
		|| !ft_strcmp(str, "--bench"))
		return (1);
	return (0);
}

void	check_duplicate(t_stack *stack)
{
	t_stack	*runner;
	t_stack	*current;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content == runner->content)
			{
				ft_printf("Error : [argument duplications]");
				exit(1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
}

static int	is_number(char *str)
{
	int	i;

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

static void	parse_flag(char *arg, t_strategy_info *flag_list)
{
	if (is_valid_flag(arg) == 0)
	{
		ft_printf("Error : [flag incorrect]\n");
		exit(1);
	}
	if (ft_strcmp(arg, "--bench") == 0)
		flag_list->bench_bool = 1;
	else
		add_strategy(flag_list, arg);
}

void	check_flags(int argc, char **argv,
			t_strategy_info *flag_list, t_stack_ctrl *stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
		{
			parse_flag(argv[i], flag_list);
		}
		else
		{
			if (!is_number(argv[i]) && !ft_strchr(argv[i], ' '))
			{
				ft_printf("Error : [argument incorrect]");
				exit(1);
			}
			fill_stack(argv[i], stack);
		}
		i++;
	}
}

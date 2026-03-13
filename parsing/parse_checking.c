/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:41:35 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/13 14:20:17 by mamiandr         ###   ########.fr       */
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

int	check_duplicate(t_stack *stack)
{
	t_stack	*temp;

	while(stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (stack->content == temp->content)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
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

int	check_flags(int argc, char **argv,t_strategy_info *flag_list, t_stack **stack)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
		{
			if (is_valid_flag(argv[i]) == 1)
			{
				//si c'est un flag valide, on l'ajoute dans strategy
				//on teste si
			}
			else
				return (-1);
		}
		else if (!is_number(argv[i]))
			if (ft_strlen(argv[i]) == 1)
				return (5);

		i++;
	}
	return (0);
}

int	check_bench_flag(int argc, char **argv)
{
	if (argc <= 2 || !argv)
		return (0);
	if (ft_strcmp(argv[1], "--bench") == 0)
		return (1);
	return (0);
}



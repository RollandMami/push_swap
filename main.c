/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:44:45 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/13 16:15:32 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

static void	initialisation(t_strategy_info *flag, t_stack_ctrl stack)
{
	
}

int	main(int argc, char *argv[])
{
	t_strategy_info	flag_list;
	t_stack_ctrl	stack_a;
	t_bench			bench;
	int				error;

	if (argc < 2)
	{
		ft_printf("Error: [Pas d'arguments]\n");
		return (1);
	}
	flag_list = NULL;
	stack_a = NULL;
	bench	= NULL;

	error = check_flags(argc, argv, &flag_list, &stack_a)


	return (0);
}

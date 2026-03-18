/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:44:45 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/18 21:54:06 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

static void	initialisation(t_strategy_info *flag,
				t_stack_ctrl *stack, t_bench *bench)
{
	ft_memset(flag, 0, sizeof(t_strategy_info));
	ft_memset(stack, 0, sizeof(t_stack_ctrl));
	ft_memset(bench, 0, sizeof(t_bench));
}

int	main(int argc, char *argv[])
{
	t_strategy_info	flag_list;
	t_stack_ctrl	stack_a;
	t_bench			bench;
	float			disorder;

	if (argc < 2)
	{
		ft_printf("Error: [Pas d'arguments]\n");
		return (1);
	}
	if (argc == 2)
	{
		ft_printf("loggin_info : on ne fait rien pour un seul argument\n");
		return (1);		
	}
	initialisation(&flag_list, &stack_a, &bench);
	check_flags(argc, argv, &flag_list, &stack_a);
	check_duplicate(stack_a.head);
	if (is_sorted(&stack_a))
	{
		ft_printf("loggin_info : la stack est déjà triée\n");
		free_stack(&stack_a);
		free_strategy(&flag_list);	
		return (0);	
	}
	disorder = compute_disorder(stack_a.head);
	push_swap(&flag_list, &stack_a, &bench, disorder);
	if (flag_list.bench_bool)
	{
		bench.disorder = disorder;
		print_bench(&flag_list, &bench);
	}
	free_stack(&stack_a);
	free_strategy(&flag_list);
	return (0);
}

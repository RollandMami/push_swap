/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:44:45 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/21 07:18:10 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	initialisation(t_strategy_info *flag,
				t_stack_ctrl *stack, t_bench *bench)
{
	ft_memset(flag, 0, sizeof(t_strategy_info));
	ft_memset(stack, 0, sizeof(t_stack_ctrl));
	ft_memset(bench, 0, sizeof(t_bench));
	bench->formula = NULL;
}

static void	parse_and_check(int ac, char **av, t_stack_ctrl *a,
				t_strategy_info *f)
{
	if (ac == 2 && !ft_strchr(av[1], ' '))
	{
		if (is_number(av[1]))
			exit(0);
		error_exit(a, NULL, f, NULL);
	}
	check_flags(ac, av, f, a);
	check_duplicate(a);
}

int	main(int argc, char *argv[])
{
	t_strategy_info	flag_list;
	t_stack_ctrl	stack_a;
	t_bench			bench;
	float			disorder;

	initialisation(&flag_list, &stack_a, &bench);
	if (argc < 2)
		return (0);
	parse_and_check(argc, argv, &stack_a, &flag_list);
	if (is_sorted(&stack_a))
	{
		free_all(&stack_a, NULL, &flag_list, &bench);
		return (0);
	}
	disorder = compute_disorder(stack_a.head);
	bench.disorder = disorder;
	prepare_stack(&stack_a, &bench);
	push_swap(&flag_list, &stack_a, &bench);
	if (flag_list.bench_bool)
		print_bench(&flag_list, &bench);
	free_all(&stack_a, NULL, &flag_list, &bench);
	return (0);
}

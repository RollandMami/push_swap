/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:44:45 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/15 20:54:18 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

static void	initialisation(t_strategy_info *flag, t_stack_ctrl *stack, t_bench *bench)
{
	ft_memset(flag, 0, sizeof(t_strategy_info));
	ft_memset(stack, 0, sizeof(t_stack_ctrl));
	ft_memset(bench, 0, sizeof(t_bench));
}

static void	free_stack(t_stack_ctrl *stack)
{
	t_stack *current;
	t_stack	*temp;

	if (!stack || !stack->head)
		return ;
	current = stack->head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	stack->head = NULL;
	stack->last = NULL;
	stack->size = 0;
}

static void	free_strategy(t_strategy_info *strategy)
{
	t_strategy *current;
	t_strategy *temp;

	if (!strategy || !strategy->head)
		return ;
	current = strategy->head;
	while(current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	strategy->bench_bool = 0;
	strategy->head = NULL;
	strategy->last = NULL;
	strategy->size = 0;
}

int	main(int argc, char *argv[])
{
	t_strategy_info	flag_list;
	t_stack_ctrl	stack_a;
	t_bench			bench;

	if (argc < 2)
	{
		ft_printf("Error: [Pas d'arguments]\n");
		return (1);
	}
	initialisation(&flag_list, &stack_a, &bench);
	// verification des flags et args + fill stack
	check_flags(argc, argv, &flag_list, &stack_a);
	check_duplicate(stack_a.head);

	ft_printf("%d",  stack_a.last->content);
	free_stack(&stack_a);
	free_strategy(&flag_list);
	return (0);
}
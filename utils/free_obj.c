/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:38:23 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/18 17:39:29 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_strategy(t_strategy_info *strategy)
{
	t_strategy	*current;
	t_strategy	*temp;

	if (!strategy || !strategy->head)
		return ;
	current = strategy->head;
	while (current)
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

void	free_stack(t_stack_ctrl *stack)
{
	t_stack	*current;
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
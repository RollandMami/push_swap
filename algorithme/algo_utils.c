/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:39:22 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 18:17:53 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

int	is_sorted(t_stack_ctrl *stack)
{
	t_stack	*current;

	if (!stack || !stack->head || stack->size < 2)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack	*get_min(t_stack_ctrl *stack)
{
	t_stack	*current;
	t_stack	*min;

	if (!stack || !stack->head)
		return (NULL);
	current = stack->head->next;
	min = stack->head;
	while (current)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
	}
	return (min);
}

int	get_position(t_stack_ctrl *stack, t_stack *min)
{
	t_stack	*current;
	int		pos;

	if (!stack || !min)
		return (-1);
	current = stack->head;
	pos = 0;
	while (current)
	{
		if (current == min)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

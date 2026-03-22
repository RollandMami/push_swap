/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:39:22 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/21 18:12:34 by mamiandr         ###   ########.fr       */
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

int	get_median(t_stack_ctrl *stack, int len)
{
	int		i;
	int		*temp;
	t_stack	*runner;

	if (!stack || len <= 0)
		return (-1);
	temp = malloc (sizeof(int) * len);
	if (!temp)
		return (-1);
	i = 0;
	runner = stack->head;
	while (i < len && runner)
	{
		temp[i] = runner->index;
		i++;
		runner = runner->next;
	}
	quick_sort(temp, 0, len - 1);
	i = temp[len / 2];
	free(temp);
	return (i);
}

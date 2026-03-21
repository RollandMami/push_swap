/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:28:35 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/21 07:19:21 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	*stack_to_array(t_stack_ctrl *stack)
{
	int		*result;
	int		i;
	t_stack	*current;

	if (!stack || !stack->head)
		return (NULL);
	result = malloc (sizeof(int) * stack->size);
	if (!result)
		return (NULL);
	i = 0;
	current = stack->head;
	while (current)
	{
		result[i] = current->content;
		i++;
		current = current->next;
	}
	return (result);
}

void	index_stack(t_stack_ctrl *stack, int *array)
{
	t_stack	*node;
	int		index;

	node = stack->head;
	while (node)
	{
		index = index_binary_srch(node->content, array, stack->size);
		if (index < 0)
		{
			ft_printf("le nombre n'est pas dans le tableau triee");
			return ;
		}
		node->index = index;
		node = node->next;
	}
}

t_stack	*find_by_index(t_stack_ctrl *stack, int index)
{
	t_stack	*node;

	if (!stack || !stack->head)
		return (NULL);
	node = stack->head;
	while (node)
	{
		if (node->index == index)
			return (node);
		node = node->next;
	}
	return (NULL);
}

int	index_binary_srch(int value, int *tab, int size)
{
	int	min;
	int	max;
	int	mean;

	if (!tab || size <= 0)
		return (-1);
	min = 0;
	max = size - 1;
	while (min <= max)
	{
		mean = min + ((max - min) / 2);
		if (value == tab[mean])
			return (mean);
		else if (value > tab[mean])
			min = mean + 1;
		else
			max = mean - 1;
	}
	return (-1);
}

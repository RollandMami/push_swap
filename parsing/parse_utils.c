/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:28:35 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/17 22:09:28 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int is_sorted(t_stack_ctrl *stack)
{
	t_stack *current;

	if (!stack || !stack->head || stack->size < 2)
		return (1);
	current = stack->head;
	while(current->next)
	{
        if (current->content > current->next->content)
            return (0);
		current = current->next;
	}
	return (1);
}

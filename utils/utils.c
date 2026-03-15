/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolland <rolland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:23:29 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/14 22:04:55 by rolland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp(const char *s1, const char*s2)
{
	int	i;

	if (!s1 || !s2 || ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

float	compute_disorder(t_stack *stack_a)
{
	float	mistakes;
	float	total_pairs;
	t_stack	*current;
	t_stack	*parser;

	if (!stack_a)
		return (-1);
	mistakes = 0;
	total_pairs = 0;
	current = stack_a;
	while (current)
	{
		parser = current->next;
		while (parser)
		{
			total_pairs += 1;
			if (current->content > parser->content)
				mistakes += 1;
			parser = parser->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

void	add_strategy(t_strategy_info **strategy, char *argv)
{
	t_strategy	*new_node;

	new_node = malloc (sizeof(t_strategy));
	if (!new_node)
		return (NULL);
	new_node->content = argv;
	new_node->next = NULL;

	if ((*strategy)->head == NULL)
	{
		(*strategy)->head = new_node;
		(*strategy)->last = new_node;
	}
	else
	{
		(*strategy)->last->next = new_node;
		(*strategy)->last=new_node;
	}
	(*strategy)->size++;
	if (ft_strcmp(argv, "--bench") == 0)
		(*strategy)->bench_bool = 1;

}

void	fill_stack(char *str, t_stack_ctrl *stack)
{
	char		**sub;
	t_stack		*new_node;
	long		contents;
	int			i;

	if (ft_strchr(str, ' '))
	{
		sub = ft_split(str, ' ');
		i = 0;
		while(sub[i])
		{
			fill_stack(sub[i], stack);
			free(sub[i]);
			i++;
		}
		free(sub);
		return ;
	}
	new_node = malloc (sizeof(t_stack));
	if (!new_node)
		return ;
	contents = ft_atol(str);
	if (contents > 2147483647 || contents < -2147483648)
	{
		ft_printf("Error : [INT min max over flow >>> %d]", contents);
		return ;
	}
	new_node->content = ft_atoi(str);
	new_node->index = 0;
	new_node->next = NULL;
	if (!stack->head)
		stack->head = new_node;
	else
		stack->last->next = new_node;
	stack->last = new_node;
	stack->size++;
}

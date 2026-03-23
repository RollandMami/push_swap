/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 08:21:16 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/23 08:21:16 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

int	is_rev_sorted_block(t_stack_ctrl *stack, int len)
{
	t_stack	*tmp;

	*tmp = stack->head;
	while (len > 0 && tmp && tmp->next)
	{
		if (tmp->index < tmp->next->index)
			return (0);
		tmp = tmp->next;
		len--;
	}
	return (1);
}

static void	sta_utils(t_stack_ctrl *a, t_stack_ctrl *b, t_bench *bn,
		t_strategy_info *st)
{
	int	f;
	int	s;
	int	t;

	f = a->head->index;
	s = a->head->next->index;
	t = a->head->next->next->index;
	if (f > s && s < t && f < t)
		sa(a, bn, 0, st->bench_bool);
	if (f > s && s < t && f > t)
	{
		sa(a, bn, 0, st->bench_bool);
		pb(a, b, bn, st->bench_bool);
		sa(a, bn, 0, st->bench_bool);
		pa(a, b, bn, st->bench_bool);
	}
	else if (f < s && s > t && f > t)
	{
		pb(a, b, bn, st->bench_bool);
		sa(a, bn, 0, st->bench_bool);
		pa(a, b, bn, st->bench_bool);
		sa(a, bn, 0, st->bench_bool);
	}	
}

void	sort_three_a(t_stack_ctrl *a, t_stack_ctrl *b, t_bench *bn,
		t_strategy_info *st)
{
	int	f;
	int	s;
	int	t;

	f = a->head->index;
	s = a->head->next->index;
	t = a->head->next->next->index;
	if (f < s && s < t)
		return ;
	sta_utils(a, b, bn, st);
	if (f < s && s > t && f < t)
	{
		pb(a, b, bn, st->bench_bool);
		sa(a, bn, 0, st->bench_bool);
		pa(a, b, bn, st->bench_bool);
	}
	else if (f > s && s > t)
	{
		sa(a, bn, 0, st->bench_bool);
		pb(a, b, bn, st->bench_bool);
		sa(a, bn, 0, st->bench_bool);
		pa(a, b, bn, st->bench_bool);
		sa(a, bn, 0, st->bench_bool);
	}
}

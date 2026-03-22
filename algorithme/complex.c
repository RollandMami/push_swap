/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:38:25 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/22 21:17:42 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

int is_sorted_block(t_stack_ctrl *stack, int len)
{
	t_stack *tmp = stack->head;
	while (--len > 0 && tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index) return (0);
		tmp = tmp->next;
	}
	return (1);
}

int is_rev_sorted_block(t_stack_ctrl *stack, int len)
{
	t_stack *tmp = stack->head;
	while (--len > 0 && tmp && tmp->next)
	{
		if (tmp->index < tmp->next->index) return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sta_utils(t_stack_ctrl *a, t_stack_ctrl *b, t_bench *bn,
		t_strategy_info *st)
{
	int f = a->head->index;
	int s = a->head->next->index;
	int t = a->head->next->next->index;

	if (f > s && s < t && f > t) // 3 1 2
	{
		sa(a, bn, 0, st->bench_bool);
		pb(a, b, bn, st->bench_bool);
		sa(a, bn, 0, st->bench_bool);
		pa(a, b, bn, st->bench_bool);
	}
	else if (f < s && s > t && f > t) // 2 3 1
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
	// On utilise les index pour comparer (0, 1, 2...)
	int f = a->head->index;
	int s = a->head->next->index;
	int t = a->head->next->next->index;

	if (f < s && s < t) return ; // Déjà trié
	if (f > s && s < t && f < t) sa(a, bn, 0, st->bench_bool); // 2 1 3
	else if (f < s && s > t && f < t) // 1 3 2
	{
		pb(a, b, bn, st->bench_bool);
		sa(a, bn, 0, st->bench_bool);
		pa(a, b, bn, st->bench_bool);
	}
	else if (f > s && s > t) // 3 2 1
	{
		sa(a, bn, 0, st->bench_bool);
		pb(a, b, bn, st->bench_bool);
		sa(a, bn, 0, st->bench_bool);
		pa(a, b, bn, st->bench_bool);
		sa(a, bn, 0, st->bench_bool);
	}
	sta_utils(a, b, bn, st);
}

void quick_sort_a(t_stack_ctrl *a, t_stack_ctrl *b, int len, t_bench *bn, t_strategy_info *st)
{
	int pivot;
	int items[2] = {0, 0}; // [0] = push_b, [1] = rotate_a

	// OPTIMISATION 1 : Si le bloc est déjà trié, on ne touche à rien
	if (is_sorted_block(a, len))
		return ;
	// OPTIMISATION 2 : Cas de base pour 2 ou 3 éléments
	if (len <= 3)
	{
		if (len == 2 && a->head->index > a->head->next->index)
			sa(a, bn, 0, st->bench_bool);
		else if (len == 3)
			sort_three_a(a, b, bn, st);
		return ;
	}
	pivot = get_median(a, len);
	for (int i = 0; i < len; i++)
	{
		if (a->head->index < pivot)
			items[0] += (pb(a, b, bn, st->bench_bool), 1);
		else
			items[1] += (ra(a, bn, 0, st->bench_bool), 1);
	}
	// ROLLBACK : On remonte A uniquement si on n'a pas traité la pile entière
	if (items[1] != a->size)
		for (int i = 0; i < items[1]; i++) rra(a, bn, 0, st->bench_bool);
	
	quick_sort_a(a, b, items[1], bn, st); // Récursion sur les grands restés sur A
	quick_sort_b(a, b, items[0], bn, st); // Récursion sur les petits envoyés sur B
}

void quick_sort_b(t_stack_ctrl *a, t_stack_ctrl *b, int len, t_bench *bn, t_strategy_info *st)
{
	int pivot;
	int items[2] = {0, 0}; // [0] = push_a, [1] = rotate_b

	// OPTIMISATION 1 : Si B est déjà trié décroissant, on repousse tout sur A
	if (is_rev_sorted_block(b, len))
	{
		while (len--) pa(a, b, bn, st->bench_bool);
		return ;
	}
	// OPTIMISATION 2 : Cas de base (envoie sur A et trie avec sa si besoin)
	if (len <= 3)
	{
		while (len--)
		{
			if (b->size > 1 && b->head->index < b->head->next->index) sb(b, bn, 0, st->bench_bool);
			pa(a, b, bn, st->bench_bool);
			if (a->size > 1 && a->head->index > a->head->next->index) sa(a, bn, 0, st->bench_bool);
		}
		return ;
	}
	pivot = get_median(b, len);
	for (int i = 0; i < len; i++)
	{
		if (b->head->index >= pivot)
			items[0] += (pa(a, b, bn, st->bench_bool), 1);
		else
			items[1] += (rb(b, bn, 0, st->bench_bool), 1);
	}
	quick_sort_a(a, b, items[0], bn, st); // On trie les grands arrivés sur A
	// ROLLBACK : On remonte B uniquement si nécessaire
	if (items[1] != b->size)
		for (int i = 0; i < items[1]; i++) rrb(b, bn, 0, st->bench_bool);
	quick_sort_b(a, b, items[1], bn, st); // On trie les petits restés sur B
}

void complex(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_bench *bench, t_strategy_info *strategy)
{
	if (is_sorted(stack_a))
		return ;
	// Lancement de la récursion sur la taille totale de A
	quick_sort_a(stack_a, stack_b, stack_a->size, bench, strategy);
}



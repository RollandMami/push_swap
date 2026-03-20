/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:07:53 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/20 20:10:43 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

int	tab_partition(int *tableau, int bas, int haut)
{
	int	i;
	int	pivot;
	int	j;
	int	temp;

	i = bas - 1;
	j = bas;
	pivot = tableau[haut];
	while (j < haut)
	{
		if (tableau[j] < pivot)
		{
			i++;
			temp = tableau[i];
			tableau[i] = tableau[j];
			tableau[j] = temp;
		}
		j++;
	}
	temp = tableau[i + 1];
	tableau[i + 1] = tableau[haut];
	tableau[haut] = temp;
	return (i + 1);
}

void	quick_sort(int	*tableau, int bas, int haut)
{
	int	pi;

	if (bas < haut)
	{
		pi = tab_partition(tableau, bas, haut);
		quick_sort(tableau, bas, pi - 1);
		quick_sort(tableau, pi + 1, haut);
	}
}

void	insertion_sort(int	*tableau, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = tableau[i];
		j = i - 1;
		while (j >= 0 && tableau[j] > key)
		{
			tableau[j + 1] = tableau[j];
			j--;
		}
		tableau[j + 1] = key;
		i++;
	}
}

void	prepare_stack(t_stack_ctrl *stack, t_bench *bench)
{
	int	*tab;

	if (!stack || !bench || stack->size <= 1)
		return ;
	tab = stack_to_array(stack);
	if (!tab)
		return ;
	if (stack->size <= 15 || bench->disorder >= 0.9)
		insertion_sort(tab,stack->size);
	else
		quick_sort(tab, 0, stack->size - 1);
	index_stack(stack, tab);
	free(tab);
}

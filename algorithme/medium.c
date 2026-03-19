/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:38:12 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/19 16:49:22 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

void	medium(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b,
			t_bench *bench, t_strategy_info *strategy)
{
	(void)stack_a;
	(void)stack_b;
	(void)bench;
	(void)strategy;

	// 1. PHASE DE PREPARATION
	int *stack_to_array(t_stack_ctrl *stack);
	void quick_sort(int *array, int start, int end);
	int binary_search(int *array, int size, int value); // recherche l'index du noeud dans le tableau trié
	void index_stack(t_stack_ctrl *stack, int *sorted_array); // remplace stack->index des noeuds par leurs index dans le tableau trié
	// index_stack utilise le binary search pour trouver l'index de chaque noeud dans le tableau trié

	// 2. PHASE DE TRANSFERT (A -> B)
	int get_max_pos(t_stack_ctrl *stack); // trouve la position du noeud avec l'index le plus élevé dans stack_a
	void rotate_to_top(t_stack_ctrl *stack, int pos, char stack_name); // fait les rotations nécessaires pour amener le noeud à la position pos en haut de stack_a
	// get_max_pos trouve la position du noeud avec l'index le plus élevé dans stack_a, puis rotate_to_top effectue les rotations nécessaires pour amener ce noeud en haut de stack_a, ensuite on push ce noeud vers stack_b. On répète ce processus jusqu'à ce que stack_a soit vide.

	// 3. PHASE DE RECONSTRUCTION (B -> A)
	void push_back_to_a(t_stack_ctrl *stack_a, t_stack_ctrl *stack_b); // pousse les éléments de stack_b vers stack_a dans l'ordre correct
	// push_back_to_a utilise les index des noeuds dans stack_b pour déterminer l'ordre
}

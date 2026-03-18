/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamiandr <mamiandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:54:42 by mamiandr          #+#    #+#             */
/*   Updated: 2026/03/18 22:23:01 by mamiandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*get_strategy_name(t_strategy_info *flag)
{
	char	*nom;

    if (flag->last && flag->last->content)
	{
		nom = flag->last->content + 2;
		if (nom && *nom >= 'a' && *nom <= 'z')
			*nom -=32;
		return (nom);
	}
    return ("Adaptative");
}

char	*get_formula(char *strategy)
{
    if (ft_strcmp(strategy, "Simple") == 0)
        return ("O(n2)");
	else if (ft_strcmp(strategy, "Medium") == 0)
        return ("O(n√n)");
	else if (ft_strcmp(strategy, "Adaptative") == 0)
        return ("O(n√n)");
    else if (ft_strcmp(strategy, "Complex") == 0)
        return ("O(nlogn)");
    return ("N/A");
}

void	print_bench(t_strategy_info *strategy,t_bench *b)
{
	char    *name;
    char    *formula;

    if (!b || strategy->bench_bool == 0)
        return ;
    
    name = get_strategy_name(strategy);
    formula = get_formula(name);
	ft_printf("[bench] disorder:  %d%%\n", (int)(b->disorder * 100));
	ft_printf("[bench] strategy:   %s / %s\n", name, formula);
	ft_printf("[bench] total_ops: %d\n", b->total);
	ft_printf("[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n", b->sa,
				b->sb, b->ss, b->pa, b->pb);
	ft_printf("[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d  rrb:  %d  rrr:  %d\n",
				b->ra, b->rb, b->rr, b->rra, b->rrb, b->rrr);
	
}
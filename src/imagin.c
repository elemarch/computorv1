/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 19:09:39 by elemarch          #+#    #+#             */
/*   Updated: 2015/05/05 21:06:20 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computorv1.h"

void			i_colors(t_eq *e)
{
	ft_putstr("    Solution 1 = (- \033[32mB\033[0m + \\/(D)i) /");
	ft_putstr(" 2(\033[33mA\033[0m)\n");
	ft_putstr("    Solution 2 = (- \033[32mB\033[0m - \\/(D)i) /");
	ft_putstr(" 2(\033[33mA\033[0m)\n\n");
	ft_putstrf("    Solution 1 = (- (\033[32m$F\033[0m) + \\/(D)i) /", e->b);
	ft_putstrf(" 2(\033[33m$F\033[0m)\n", e->a);
	ft_putstrf("    Solution 2 = (- \033[32m$F\033[0m - \\/(D)i) /", e->b);
	ft_putstrf(" 2(\033[33m$F\033[0m)\n\n", e->a);
}

void			i_simple(t_eq *e)
{
	ft_putstr("    Solution 1 = (- B + \\/(D)i) / 2(A)\n");
	ft_putstr("    Solution 2 = (- B - \\/(D)i) / 2(A)\n\n");
	ft_putstrf("    Solution 1 = (- ($F) + \\/(D)) /", e->b);
	ft_putstrf(" 2($F)\n", e->a);
	ft_putstrf("    Solution 2 = (- ($F) - \\/(D)) /", e->b);
	ft_putstrf(" 2($F)\n\n", e->a);
}

void			solve_imagin(t_eq *e, int o)
{
	float		p1;
	float		p2;

	p1 = (-e->b) / 2 * e->a;
	p2 = (solve_sqrt(-(e->b * e->b - 4 * e->a * e->c))) / 2 * e->a;
	if (!OPT_H && OPT_M)
		OPT_C ? i_colors(e) : i_simple(e);
	if (!OPT_H && OPT_C)
	{
		ft_putstrf("    Solution 1 = \033[31m$F ", p1);
		ft_putstrf("+ $Fi\n\033[0m", p2);
		ft_putstrf("    Solution 2 = \033[31m$F ", p1);
		ft_putstrf("- $Fi\n\033[0m", p2);
	}
	else
	{
		ft_putstrf("    Solution 1 = $F ", p1);
		ft_putstrf("+ $Fi\n", p2);
		ft_putstrf("    Solution 2 = $F ", p1);
		ft_putstrf("- $Fi\n", p2);
	}
}

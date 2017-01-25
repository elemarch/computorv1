/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_hard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 21:13:51 by elemarch          #+#    #+#             */
/*   Updated: 2015/05/05 21:13:53 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computorv1.h"

float			solve_hard_discr(t_eq *e, int o)
{
	float		d;

	d = (e->b * e->b) - (4 * e->a * e->c);
	if (!OPT_H && OPT_M)
	{
		if (OPT_C)
			shd_colors(e);
		else
			shd_simple(e);
	}
	if (OPT_C && !OPT_H)
		ft_putstrf("    D = \033[31m$F\n\033[0m\n", d);
	else if (!OPT_H)
		ft_putstrf("    D = $F\n", d);
	if (d < 0 && !OPT_H)
		ft_putstr("    Discriminent is negative: two complex solutions.\n");
	else if (d == 0 && !OPT_H)
	{
		ft_putstr("    Discriminent is null: one solution.\n");
		d = 0;
	}
	else if (d >= 0 && !OPT_H)
		ft_putstr("    Discriminent is positive: two solution.\n");
	return (d);
}

void			solve_hard_one(t_eq *e, int o)
{
	float		s;

	s = -(e->b / (2 * e->a));
	if (!OPT_H && OPT_M)
	{
		if (OPT_C)
		{
			ft_putstr("    S = - (\033[32mB\033[0m / 2\033[33mA\033[0m)\n");
			ft_putstrf("    S = - (\033[32m$F\033[0m /", e->b);
			ft_putstrf(" 2(\033[33m$F\033[0m))\n", e->a);
		}
		else
		{
			ft_putstr("    S = - (B / 2A)\n");
			ft_putstrf("    S = - ($F /", e->b);
			ft_putstrf(" 2($F))\n", e->a);
		}
	}
	if (OPT_C)
		ft_putstrf("    Solution = \033[31m$F\n\033[0m", s);
	else
		ft_putstrf("             = $F\n", s);
}

void			sht_colors(t_eq *e)
{
	ft_putstr("    Solution 1 = (- \033[32mB\033[0m + \\/(D)) /");
	ft_putstr(" 2(\033[33mA\033[0m)\n");
	ft_putstr("    Solution 2 = (- \033[32mB\033[0m - \\/(D)) /");
	ft_putstr(" 2(\033[33mA\033[0m)\n\n");
	ft_putstrf("    Solution 1 = (- (\033[32m$F\033[0m) + \\/(D)) /", e->b);
	ft_putstrf(" 2(\033[33m$F\033[0m)\n", e->a);
	ft_putstrf("    Solution 2 = (- (\033[32m$F\033[0m) - \\/(D)) /", e->b);
	ft_putstrf(" 2(\033[33m$F\033[0m)\n\n", e->a);
}

void			sht_simple(t_eq *e)
{
	ft_putstr("    Solution 1 = (- B + \\/(D)) / 2(A)\n");
	ft_putstr("    Solution 2 = (- B - \\/(D)) / 2(A)\n\n");
	ft_putstrf("    Solution 1 = (- ($F) + \\/(D)) /", e->b);
	ft_putstrf(" 2($F)\n", e->a);
	ft_putstrf("    Solution 2 = (- ($F) - \\/(D)) /", e->b);
	ft_putstrf(" 2($F)\n\n", e->a);
}

void			solve_hard_two(t_eq *e, int o)
{
	float		s1;
	float		s2;

	s1 = (-e->b + solve_sqrt(e->b * e->b - 4 * e->a * e->c)) / 2 * e->a;
	s2 = (-e->b - solve_sqrt(e->b * e->b - 4 * e->a * e->c)) / 2 * e->a;
	if (!OPT_H && OPT_M)
	{
		if (OPT_C)
			sht_colors(e);
		else
			sht_simple(e);
	}
	if (!OPT_H && OPT_C)
	{
		ft_putstrf("    Solution 1 = \033[31m$F\n\033[0m", s1);
		ft_putstrf("    Solution 2 = \033[31m$F\n\033[0m", s2);
	}
	else
	{
		ft_putstrf("    Solution 1 = $F\n", s1);
		ft_putstrf("    Solution 2 = $F\n", s2);
	}
}

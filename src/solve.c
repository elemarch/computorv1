/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 21:10:22 by elemarch          #+#    #+#             */
/*   Updated: 2015/05/05 21:13:46 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computorv1.h"

void			solve_simple_colors(t_eq *e)
{
	ft_putstr("    Shape : \033[32mA\033[0mx + \033[35mB\033[0m = 0\n");
	ft_putstrf("    Values : \033[32m$F\033[0mx + ", e->b);
	ft_putstrf("\033[35m$F\033[0m = 0\n", e->c);
	ft_putstr("    Solution = - (\033[35mB\033[0m / \033[32mA\033[0m)\n");
	ft_putstrf("             = - (\033[35m$F\033[0m / ", e->c);
	ft_putstrf("\033[32m$F\033[0m)\n", e->b);
}

void			solve_simple(t_eq *e, int o)
{
	float		s;

	s = -(e->c / e->b);
	if (!OPT_H && OPT_M)
	{
		if (OPT_C)
			solve_simple_colors(e);
		else
		{
			ft_putstr("    Shape : Ax + B = 0\n");
			ft_putstrf("    Values : $Fx + ", e->b);
			ft_putstrf("$F = 0", e->c);
			ft_putstr("    Solution = - (B / A)\n");
			ft_putstrf("             = - ($F / ", e->c);
			ft_putstrf("$F)\n", e->b);
		}
	}
	if (OPT_C)
		ft_putstrf("             = \033[31m$F\033[0m\n", s);
	else
		ft_putstrf("             = $F\n", s);
}

void			solve_hard(t_eq *e, int o)
{
	float		d;

	d = solve_hard_discr(e, o);
	if (d < 0)
		solve_imagin(e, o);
	else if (d == 0)
		solve_hard_one(e, o);
	else if (d > 0)
		solve_hard_two(e, o);
}

void			solve_eq(t_eq *e, int o)
{
	ft_putstr("------- Solving equation -----------------------\n    ");
	if (e->p == 0)
	{
		ft_putstr("Not a polynomial equation (degree 0).\n    ");
		if (e->c)
			ft_putstr("No solution.\n");
		else
			ft_putstr("Every number as a solution.\n");
	}
	else if (e->p == 1 || e->a == 0)
	{
		ft_putstr("Simple polynomial equation (degree 1).\n\n");
		solve_simple(e, o);
	}
	else if (e->p == 2)
	{
		ft_putstr("Polynomial equation (degree 2).\n\n");
		solve_hard(e, o);
	}
	else if (e->p >= 3)
	{
		ft_putstr("Polynomial equation (degree superior or equal to 3).\n");
		ft_putstr("    I can't solve this.\n");
	}
}

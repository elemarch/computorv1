/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 16:04:31 by elemarch          #+#    #+#             */
/*   Updated: 2015/05/05 21:05:49 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computorv1.h"

void	shd_colors(t_eq *e)
{
	ft_putstr("    D = \033[32mB\033[0m^2 - 4\033[33mA\033[0m");
	ft_putstr("\033[35mC\033[0m\n");
	ft_putstrf("    D = \033[32m$F\033[0m^2 - ", e->b);
	ft_putstrf("4(\033[33m$F\033[0m)", e->a);
	ft_putstrf("(\033[35m$F\033[0m)\n", e->c);
}

void	shd_simple(t_eq *e)
{
	ft_putstrf("    D = B^2 - 4AC\n    D = $F^2 - ", e->b);
	ft_putstrf("4($F)", e->a);
	ft_putstrf("($F)\n\n", e->c);
}

float	solve_sqrt(float nb)
{
	float calc;
	float diff;

	if (nb == 0.0 || nb == 1.0)
		return (nb);
	calc = nb;
	diff = calc;
	calc = 0.5 * (calc + nb / calc);
	while (calc != diff)
	{
		diff = calc;
		calc = 0.5 * (calc + nb / calc);
	}
	return (calc);
}

void	eq_print(t_eq eq, int o)
{
	if (eq.p < 3 && !OPT_H)
	{
		ft_putstr("------- Reduced equation -----------------------\n    ");
		if (OPT_C)
		{
			ft_putstrf("(\033[33m$F\033[0m)X^2 + ", eq.a);
			ft_putstrf("(\033[32m$F\033[0m)X + ", eq.b);
			ft_putstrf("(\033[35m$F\033[0m) = 0\n\n", eq.c);
		}
		else
		{
			ft_putstrf("($F)X^2 + ", eq.a);
			ft_putstrf("($F)X + ", eq.b);
			ft_putstrf("($F) = 0\n\n", eq.c);
		}
	}
}

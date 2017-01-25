/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 16:04:31 by elemarch          #+#    #+#             */
/*   Updated: 2015/05/05 21:07:38 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computorv1.h"

void	init_eq(t_eq *e)
{
	eq->a = 0;
	eq->b = 0;
	eq->c = 0;
	eq->p = 0;
}

int		main(int argc, char const **argv)
{
	t_eq	eq;
	int		o;
	int		n;

	o = 0;
	n = 0;
	ft_putstr("------------------------------------------------\n");
	ft_putstr("  ___ _____ __  __ ____ __  __ ____ _____ _v1_ \n");
	ft_putstr(" / __(  _  (  \\/  (  _ (  )(  (_  _(  _  (  _ \\\n");
	ft_putstr("( (__ )(_)( )    ( )___/)(__)(  )(  )(_)( )   /\n");
	ft_putstr(" \\___(_____(_/\\/\\_(__) (______)(__)(_____(_)\\_)\n");
	ft_putstr("------------------------------------------------\n");
	if (argc == 1 || (!(n = define_opts(argv, argc, &o))))
		ft_putstr("Usage :    ./computorv1 -[chm] [--] [\"equation\"]\n");
	else
	{
		parse_eq(ft_strdup(argv[n]), &eq, o);
		eq_print(eq, o);
		solve_eq(&eq, o);
	}
	ft_putstr("------------------------------------------------\n");
	return (0);
}

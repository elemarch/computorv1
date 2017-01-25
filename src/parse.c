/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 21:07:58 by elemarch          #+#    #+#             */
/*   Updated: 2015/05/05 21:08:51 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computorv1.h"

void			parse_stock(t_eq *e, char c, float f)
{
	if (c == '0')
		e->c += f;
	if (c == '1')
		e->b += f;
	if (c == '2')
		e->a += f;
}

void			print_src_color(char *src)
{
	int		i;

	i = 0;
	ft_putstr("------- Step 1 ---------------------------------\n    ");
	while (src[i])
	{
		if (src[i] == '=')
			i++;
		if (ISNUM(src[i]) && (src[i] == 0 || !ISNUM(src[i - 1])))
			ft_putstr("\033[31m");
		ft_putchar(src[i]);
		if (ISNUM(src[i]) && (!ISNUM(src[i + 1])))
			ft_putstr("\033[0m");
		i++;
	}
	ft_putchar('\n');
}

void			print_src_simple(char *src)
{
	int		i;

	i = 0;
	ft_putstr("------- Step 1 ---------------------------------\n    ");
	while (src[i])
	{
		if (src[i] == '=')
			i += 2;
		ft_putchar(src[i]);
		i++;
	}
	ft_putchar('\n');
}

void			parse_clean(char **src, int o)
{
	int		i;

	i = 0;
	while ((*src)[i] && (*src)[i] != '=')
		i++;
	if ((*src)[i + 2] != '+' && (*src)[i + 2] != '-')
		(*src)[i] = '+';
	while ((*src)[i])
	{
		if ((*src)[i] == '-')
			(*src)[i] = '+';
		else if ((*src)[i] == '+')
			(*src)[i] = '-';
		else if ((*src)[i] == '\n')
			(*src)[i] = ' ';
		i++;
	}
	if (!OPT_H && OPT_M)
	{
		if (OPT_C)
			print_src_color(*src);
		else
			print_src_simple(*src);
		ft_putstr("\n");
	}
}

void			parse_eq(char *src, t_eq *e, int o)
{
	int		i;
	int		s;
	float	f;

	s = 1;
	i = 0;
	parse_clean(&src, o);
	while (src[i])
	{
		if (src[i] == '-')
			s = -1;
		if (ISNUM(src[i]))
		{
			f = s * ft_atof(&(src[i]));
			while (src[i] && src[i] != '^')
				i++;
			i++;
			parse_stock(e, src[i], f);
			if (f != 0)
				e->p = (e->p < src[i] - '0') ? src[i] - '0' : e->p;
			s = 1;
		}
		i++;
	}
}

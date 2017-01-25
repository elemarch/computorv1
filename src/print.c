/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 16:04:31 by elemarch          #+#    #+#             */
/*   Updated: 2015/05/05 21:13:26 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computorv1.h"

void		print_step_color(int step, char *src)
{
	int		i;

	i = 0;
	if (step == 1)
	{
		while (src[i])
		{
			if (ISNUM(src[i]) && (i = 0 || !ISNUM(src[i - 1])))
				ft_putstr("\033[33m");
			ft_putchar(src[i]);
			if (ISNUM(src[i]) && (!src[i + 1] || !ISNUM(src[i + 1])))
				ft_putstr("\033[0m");
			i++;
		}
		ft_putstr("= 0\n");
	}
}

void		print_step(int step, char *src, int o)
{
	int		i;

	i = -1;
	if (step == 1)
	{
		if (OPT_C)
			print_step_color(step, src);
		else
		{
			while (src[++i] && src[i] != '=')
				ft_putchar(src[i]);
			i += 1;
			while (src[++i])
				ft_putchar(src[i]);
			ft_putstr("= 0\n");
		}
	}
}

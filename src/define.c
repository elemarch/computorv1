/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 19:05:58 by elemarch          #+#    #+#             */
/*   Updated: 2015/05/05 21:05:40 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computorv1.h"

#define IS_OPT(x) (x == 'c' || x == 'm' || x == 'h' || x == '-')

static int		define_opts_check(const char **argv, int argc)
{
	int		i;
	int		j;

	i = 0;
	while (argv[++i] && (!ft_strcmp(argv[i], "--") || (argv[i][0] == '-')))
	{
		j = 0;
		if (i == argc - 1)
			return (1);
		while (argv[i][++j])
		{
			if (!IS_OPT(argv[i][j]))
				return (0);
		}
	}
	return (1);
}

int				define_opts(const char **argv, int argc, int *o)
{
	int		i;

	if (!define_opts_check(argv, argc))
		return (0);
	i = 1;
	while (argv[i] && (!ft_strcmp(argv[i], "--") || argv[i][0] == '-'))
	{
		if (i == argc - 1)
			return (i);
		if (ft_strchr(argv[i], 'c'))
			*o |= 4;
		if (ft_strchr(argv[i], 'm'))
			*o |= 2;
		if (ft_strchr(argv[i], 'h'))
			*o |= 1;
		i++;
	}
	return (i);
}

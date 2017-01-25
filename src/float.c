/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 19:07:49 by elemarch          #+#    #+#             */
/*   Updated: 2015/05/05 21:06:01 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../computorv1.h"

void			ft_putstrf(const char *str, float n)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == 'F')
		{
			ft_putnbrf(n);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

static float	atoi_float(char *str, float ret, int signe)
{
	float	index;
	float	tmp;

	index = 10;
	if (*str == '.' || *str == ',')
		str++;
	while ((*str >= '0' && *str <= '9'))
	{
		tmp = (*str++ - '0');
		tmp /= index;
		ret += tmp;
		index *= 10;
	}
	return (ret * signe);
}

float			ft_atof(const char *str)
{
	float	ret;
	int		signe;

	ret = 0;
	if (!str)
		return (ret);
	signe = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
			|| *str == '\r' || *str == '\v' || *str == '0')
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ((*str >= '0' && *str <= '9'))
		ret = ret * 10 + (*str++ - '0');
	if (*str == '.' || *str == ',')
		return (atoi_float((char*)str, ret, signe));
	return (ret * signe);
}

static void		ft_putnbrf2(float n, int i, int fd, int count)
{
	char	temp;
	int		div;

	div = 1;
	while (n - (int)n > 0.0)
		n = n * 10;
	while (n / div >= 10)
		div = div * 10;
	while (div > 0 && count <= 6)
	{
		temp = '0' + n / div;
		write(fd, &temp, 1);
		i = i / 10;
		if (i == 1)
			write(fd, ".", 1);
		count = (i <= 1) ? count + 1 : count;
		n = (int)n % div;
		div = div / 10;
	}
	while (count++ <= 2)
		write(1, "0", 1);
}

void			ft_putnbrf(float n)
{
	int		count;
	int		div;
	int		i;

	count = 0;
	i = 1;
	div = 1;
	if (n < 0.0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n > 0.0 && n < 1.0)
	{
		count++;
		write(1, "0.", 2);
	}
	while ((n / div) >= 1)
	{
		div = div * 10;
		i = i * 10;
	}
	ft_putnbrf2(n, i, 1, count);
}

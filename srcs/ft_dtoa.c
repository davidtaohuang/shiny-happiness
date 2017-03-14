/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:50:37 by dhuang            #+#    #+#             */
/*   Updated: 2017/02/06 16:50:37 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/ft_printf.h"

int		ft_dtoa(double n, int p, char *frac)
{
	double		holder;
	int			i;
	double		tens;
	int			lastdig;

	holder = n;
	tens = 1;
	i = 0;
	while (i < p)
	{
		holder = n * tens;
		frac[i] = (long long)((holder - ((long long)holder)) * 10) + 48;
		tens *= 10;
		i++;
	}
	holder = n * tens;
	lastdig = (long long)((holder - ((long long)holder)) * 10);
	return (lastdig);
}

char	*adddigit(char *dec)
{
	char	*tmp;
	int		i;
	int		len;

	len = ft_strlen(dec);
	tmp = ft_strnew(len + 1);
	i = 0;
	if (dec[i] == '-')
		tmp[i++] = '-';
	tmp[i] = '1';
	while (i < len)
	{
		tmp[i + 1] = dec[i];
		i++;
	}
	ft_memdel((void**)&dec);
	return (tmp);
}

int		rounding(char *dec, int i)
{
	if (dec[i] <= '9' && dec[i] >= '0')
	{
		if (dec[i] < '9')
			(dec[i])++;
		else
		{
			dec[i] = '0';
			if (!i || dec[i - 1] == '-')
				return (1);
			else
				return (rounding(dec, i - 1));
		}
		if (dec[i] > '4')
			return (rounding(dec, i - 1));
	}
	return (0);
}
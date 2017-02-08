/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:51:57 by dhuang            #+#    #+#             */
/*   Updated: 2017/02/06 16:51:57 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define ARG (*pf)->f[i]->arg
#define ARGL (*pf)->f[i]->argsize
#define FGP (*pf)->f[i]->flagplus
#define FGS (*pf)->f[i]->flagspace
#define FGN (*pf)->f[i]->flagpound
#define FGM (*pf)->f[i]->flagminus
#define FGZ (*pf)->f[i]->flagzero
#define P (*pf)->f[i]->precision
#define TYPE (*pf)->f[i]->conversion
#define LT tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length

char	*makeinfnan(double n)
{
	char	*num;

	num = ft_strnew(3);
	if (isinf(n))
		ft_strcpy(num, "inf");
	else
		ft_strcpy(num, "NaN");
	if (signbit(n))
		num = ft_strjoin("-", num);
	return (num);
}

char	*makedbl(t_data **pf, int i)
{
	long long	n;
	char		*str;
	char		*frac;
	int			lastdig;
	int			len;

	n = *(double*)ARG;
	str = ft_itoa((long long)n);
	len = ft_strlen(str);
	if (*(long long*)ARG < 0)
		n *= -1;
	frac = ft_strnew(P);
	lastdig = ft_dtoa(n, P, frac);
	str = ft_strjoinreplace(str, frac);
	ft_memdel((void**)&frac);
	if (lastdig > 4)
	{
		if (rounding(str, ft_strlen(str) - 1))
		{
			str = adddigit(str);
			len++;
		}
	}
	P = len;
	return (str);
}

char	*adddecpt(char *dec, int len)
{
	char	*tmp;
	int		i;
	int		newlen;

	newlen = ft_strlen(dec);
	tmp = ft_strnew(newlen + 1);
	i = 0;
	while (i < len)
	{
		tmp[i] = dec[i];
		i++;
	}
	tmp[i] = '.';
	while (i < newlen)
	{
		tmp[i + 1] = dec[i];
		i++;
	}
	ft_memdel((void**)&dec);
	return (tmp);
}

void	formatdbl(t_data **pf, int i)
{
	char	*str;

	if (isinf(*(double*)ARG) || isnan(*(double*)ARG))
	{
		str = makeinfnan(*(double*)ARG);
		P = -1;
	}
	else
	{
		if (LENGTH == 3)
			str = makedbl(pf, i);
		else
			str = makedbl(pf, i);
		str = adddecpt(str, P);
	}
	ft_memdel((void**)&ARG);
	ARG = str;
	ARGL = ft_strlen(ARG);
}
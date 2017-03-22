/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatedbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:44:49 by dhuang            #+#    #+#             */
/*   Updated: 2017/03/21 17:44:49 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/ft_printf.h"

char	*makeexp(t_format *flags)
{
	char	*sign;
	char	*tmp;
	char	*tmp2;

	sign = ft_strnew(2);
	sign[0] = TYPE;
	if (flags->elen >= 0)
		sign[1] = '+';
	else
	{
		sign[1] = '-';
		flags->elen = -(flags->elen);
	}
	tmp = ft_itoa(flags->elen);
	if (ft_strlen(tmp) == 1)
	{
		tmp2 = ft_strjoin("0", tmp);
		ft_memdel((void**)&tmp);
		tmp = tmp2;
	}
	tmp2 = ft_strjoin(sign, tmp);
	ft_memdel((void**)&sign);
	ft_memdel((void**)&tmp);
	return (tmp2);
}

int		eprecision(t_format *flags, char **str)
{
	char			*tmp;
	unsigned int	len;

	len = ((*str)[0] == '-' ? 2 : 1) + P;
	if (ft_strlen(*str) > len)
	{
		tmp = ft_strsub(*str, 0, len);
		ft_memdel((void**)str);
		*str = tmp;
	}
	return (((*str)[0] == '-' ? 2 : 1));
}

void	makeedbl2(t_format *flags, double n, char **str, int len)
{
	char	*frac;
	int		lastdig;

	EP -= (flags->elen >= 0 ? 0 : flags->elen);
	frac = ft_strnew(EP);
	if ((*str)[0] == 0 || ((*str)[0] == '-' && (*str)[1] == 0))
	{
		lastdig = ft_etoa(n, frac, flags);
		flags->elen++;
	}
	else
	{
		EP -= len - 1;
		lastdig = ft_dtoa(n, EP, frac);
	}
	*str = ft_strjoinreplace(*str, frac);
	ft_memdel((void**)&frac);
	if (lastdig > 4)
	{
		if (rounding(*str, ft_strlen(*str) - 1))
		{
			*str = adddigit(*str);
			len++;
		}
	}
}

char	*makeedbl(t_format *flags)
{
	double		n;
	char		*str;
	int			len;
	char		*tmp;

	n = *(double*)ARG;
	str = ft_strnew(1);
	len = 0;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		len++;
	}
	tmp = ft_itoa((long long)n);
	len = ft_strlen(tmp);
	if (len == 1 && tmp[0] == '0')
		tmp[0] = 0;
	flags->elen += len - (tmp[0] ? 1 : 2);
	str = ft_strjoinreplace(str, tmp);
	ft_memdel((void**)&tmp);
	makeedbl2(flags, n, &str, len);
	EP = eprecision(flags, &str);
	return (str);
}

void	formatedbl(t_format *flags)
{
	char	*str;
	char	*tmp;

	if (isinf(*(double*)ARG) || isnan(*(double*)ARG))
	{
		str = makeinfnan(*(double*)ARG);
		P = -1;
	}
	else
	{
		if (LEN == 3)
			str = makeedbl(flags);
		else
			str = makeedbl(flags);
		str = adddecpt(str, EP);
	}
	tmp = makeexp(flags);
	str = ft_strjoinreplace(str, tmp);
	ft_memdel((void**)&tmp);
	ft_memdel((void**)&ARG);
	ARG = str;
	ARGL = ft_strlen(ARG);
	flags->bytelen = ft_strlen(ARG);
}

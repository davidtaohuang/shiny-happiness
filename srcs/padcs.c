/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:06:04 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/31 17:06:04 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_ubytes(unsigned char c)
{
	if (c < 0x80)
		return (1);
	else if (c < 0xe0)
		return (2);
	else if (c < 0xf0)
		return (3);
	else
		return (4);
}

static void	padw2(t_format *flags)
{
	char	*t1;
	char	*t2;

	t1 = ft_strnew(W - ARGL);
	t2 = ft_strdup(ARG);
	ft_memdel((void**)&ARG);
	if (FGZ)
		ft_memset(t1, '0', W - ARGL);
	else
		ft_memset(t1, ' ', W - ARGL);
	if (FGM)
	{
		ARG = ft_strjoinreplace(t1, t2);
		ft_memdel((void**)&t2);
	}
	else
	{
		ARG = ft_strjoinreplace(t2, t1);
		ft_memdel((void**)&t1);
	}
	ARGL = W;
}

static void	padw(t_format *flags)
{
	wchar_t	*t1;
	int		i;
	int		b;

	if (P < ARGL)
	{
		i = 0;
		b = 0;
		while (i < P)
			b += ft_ubytes(((char*)ARG)[i]);
		t1 = ft_wstrsub(ARG, 0, b);
		ft_memdel((void**)&ARG);
		ARG = t1;
		ARGL = P;
	}
	if (W > ARGL)
		padw2(flags);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s;
	size_t	i;

	s = ft_strnew(n);
	if (!s)
		return (NULL);
	if (s1)
	{
		i = 0;
		while (i < n)
		{
			s[i] = s1[i];
			i++;
		}
	}
	return (s);
}

static void	padcs2(t_format *flags)
{
	char	*t1;
	char	*t2;

	t1 = ft_strnew(W - ARGL);
	t2 = ft_strndup(ARG, ARGL);
	ft_memdel((void**)&ARG);
	if (FGZ)
		ft_memset(t1, '0', W - ARGL);
	else
		ft_memset(t1, ' ', W - ARGL);;
	if (FGM)
	{
		ARG = ft_pfstrnj(t2, ARGL, t1, W - ARGL);
		ft_memdel((void**)&t1);
	}
	else
	{
		ARG = ft_pfstrnj(t1, W - ARGL, t2, ARGL);
		ft_memdel((void**)&t2);
	}
	ARGL = W;
}

void		padcs(t_format *flags)
{
	char	*t1;

	if (TYPE == 'C' || TYPE == 'S' || LEN == 1)
		padw(flags);
	else
	{
		if (P < ARGL && ((LT == 's' && P >= 0) || (LT == 'c' && P > 0)))
		{
			t1 = ft_strsub(ARG, 0, P);
			ft_memdel((void**)&ARG);
			ARG = t1;
			ARGL = P;
		}
		if (W > ARGL && W)
			padcs2(flags);
	}
}

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

#define F (*pf)->f[i]
#define ARG (*pf)->f[i]->arg
#define ARGL (*pf)->f[i]->argsize
#define FGP (*pf)->f[i]->flagplus
#define FGS (*pf)->f[i]->flagspace
#define FGN (*pf)->f[i]->flagpound
#define FGM (*pf)->f[i]->flagminus
#define FGZ (*pf)->f[i]->flagzero
#define WO (*pf)->woffset
#define W (*pf)->f[i]->width
#define P (*pf)->f[i]->precision
#define TP (*pf)->f[i]->conversion
#define LT ft_tolower((*pf)->f[i]->conversion)
#define LEN (*pf)->f[i]->length

void	padw2(t_data **pf, int i)
{
	wchar_t	*t1;
	wchar_t	*t2;

	t1 = ft_wstrnew(W - ARGL);
	t2 = ft_wstrdup(ARG);
	ft_memdel((void**)&ARG);
	if (FGZ)
		ft_wset(t1, '0', W - ARGL);
	else
		ft_wset(t1, ' ', W - ARGL);
	if (FGM)
	{
		ARG = ft_wstrjoinreplace(t1, t2);
		ft_memdel((void**)&t2);
	}
	else
	{
		ARG = ft_wstrjoinreplace(t2, t1);
		ft_memdel((void**)&t1);
	}
	ARGL = W;
}

void	padw(t_data **pf, int i)
{
	wchar_t	*t1;

	if (P < ARGL)
	{
		t1 = ft_wstrsub(ARG, 0, P);
		ft_memdel((void**)&ARG);
		ARG = t1;
		ARGL = P;
	}
	if (W > ARGL)
		padw2(pf, i);
	WO += ARGL;
}

void	padcs2(t_data **pf, int i)
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

void	padcs(t_data **pf, int i)
{
	char	*t1;

	if (TP == 'C' || TP == 'S' || LEN == 1)
			padw(pf, i);
	else
	{
		if (P < ARGL)
		{
			t1 = ft_strsub(ARG, 0, P);
			ft_memdel((void**)&ARG);
			ARG = t1;
			ARGL = P;
		}
		if (W > ARGL)
			padcs2(pf, i);
	}
}

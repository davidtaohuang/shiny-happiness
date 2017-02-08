/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:06:03 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/31 18:06:03 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define SA ((char*)(*pf)->f[i]->arg)[0]
#define ARG (*pf)->f[i]->arg
#define ARGL (*pf)->f[i]->argsize
#define FGP (*pf)->f[i]->flagplus
#define FGS (*pf)->f[i]->flagspace
#define FGN (*pf)->f[i]->flagpound
#define FGM (*pf)->f[i]->flagminus
#define FGZ (*pf)->f[i]->flagzero
#define W (*pf)->f[i]->width
#define P (*pf)->f[i]->precision
#define TP (*pf)->f[i]->conversion
#define LT ft_tolower((*pf)->f[i]->conversion)
#define LEN (*pf)->f[i]->length

void	padnumflagox(t_data **pf, int i)
{
	char	*t1;
	char	*t2;

	if (LT == 'o')
	{
		t1 = ft_strnew(1);
		t1[0] = '0';
	}
	else
	{
		t1 = ft_strnew(2);
		t1[0] = '0';
		if (TP == 'x')
			t1[1] = 'x';
		else
			t1[1] = 'X';
	}
	t2 = ft_strdup(ARG);
	ft_memdel((void**)&ARG);
	ARG = ft_strjoinreplace(t2, t1);
	ft_memdel((void**)&t1);
	ARGL++;
	if (LT == 'x')
		ARGL++;
}

void	padnumsign(t_data **pf, int i)
{
	char	*t1;
	char	*t2;

	t1 = ft_strnew(1);
	if (FGP)
		t1[0] = '+';
	else
		t1[0] = ' ';
	t2 = ft_strdup(ARG);
	ft_memdel((void**)&ARG);
	ARG = ft_strjoinreplace(t2, t1);
	ft_memdel((void**)&t1);
	ARGL++;
}

void	padnum2(t_data **pf, int i)
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

void	padnum(t_data **pf, int i)
{
	char	*tmp;

	if (P > ARGL)
	{
		tmp = ft_strnew(P - ARGL);
		ft_memset(tmp, '0', P - ARGL);
		tmp = ft_strjoinreplace(tmp, ARG);
		ft_memdel((void**)&ARG);
		ARG = tmp;
		ARGL = P;
	}
	if (FGN && (LT == 'o' || LT == 'x'))
		padnumflagox(pf, i);
	if ((FGP || FGS) && (LT == 'd' || LT == 'i') && SA != '+' && SA != '-')
		padnumsign(pf, i);
	if (W > ARGL)
		padnum2(pf, i);
	if (TP == 'p')
	{
		ARGL += 2;
		((char*)ARG)[0] = '0';
		((char*)ARG)[1] = 'x';
	}
}

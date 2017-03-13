/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padhex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 23:53:01 by dhuang            #+#    #+#             */
/*   Updated: 2017/02/08 23:53:01 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*padhexwid(t_format *flags)
{
	char	*tmp;
	char	*ox;

	ox = ft_strnew(2);
	ox[0] = '0';
	ox[1] = (TYPE == 'p' ? 'x' : TYPE);
	if (P > ARGL)
	{
		tmp = ft_strnew(P - ARGL);
		ft_memset(tmp, '0', P - ARGL);
		tmp = ft_strjoinreplace(tmp, ARG);
		ft_memdel((void**)&ARG);
		ARG = tmp;
		ARGL = P;
	}
	return (ox);
}

static void	subzero(t_format *flags)
{
	char	*tmp;

	if (ARGL == 1 && P != -1 && *((char*)ARG) == '0')
	{
		*((char*)ARG) = 0;
		ARGL = 0;
	}
	if (P > ARGL)
	{
		tmp = ft_strnew(P - ARGL);
		ft_memset(tmp, '0', P - ARGL);
		tmp = ft_strjoinreplace(tmp, ARG);
		ft_memdel((void**)&ARG);
		ARG = tmp;
		ARGL = P;
	}
}

void		padhex(t_format *flags)
{
	char	*ox;
	char	*space;

	ox = padhexwid(flags);
	subzero(flags);
	if (W > ARGL + 2)
	{
		space = ft_strnew(W - ARGL - 2);
		ft_memset(space, ((FGZ && P < 1) ? '0' : ' '), W - ARGL - 2);
		if (FGZ)
			ARG = stitch3(ox, space, ARG);
		else
		{
			if (FGM)
				ARG = stitch3(ox, ARG, space);
			else
				ARG = stitch3(space, ox, ARG);
		}
	}
	else
		ARG = stitch2(ox, ARG);
	ARGL = ft_strlen(ARG);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padoct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 23:18:16 by dhuang            #+#    #+#             */
/*   Updated: 2017/02/09 23:18:16 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*padowid(t_format *flags)
{
	char	*tmp;
	char	*o;

	o = ft_strnew(1);
	o[0] = '0';
	if (ARGL == 1 && P != -1 && *((char*)ARG) == '0')
	{
		*((char*)ARG) = 0;
		ARGL = 0;
	}
	if (P == -1)
		P = 0;
	if (P > ARGL)
	{
		tmp = ft_strnew(P - ARGL);
		ft_memset(tmp, '0', P - ARGL);
		tmp = ft_strjoinreplace(tmp, ARG);
		ft_memdel((void**)&ARG);
		ARG = tmp;
		ARGL = P;
	}
	return (o);
}

void		padoct(t_format *flags)
{
	char	*o;
	char	*space;

	o = padowid(flags);
	if (W > ARGL)
	{
		space = ft_strnew(W - ARGL);
		ft_memset(space, ((FGZ && P < 1) ? '0' : ' '), W - ARGL);
		if (FGZ)
			ARG = stitch3(o, space, ARG);
		else
		{
			if (FGM)
				ARG = stitch3(o, ARG, space);
			else
				ARG = stitch3(space, o, ARG);
		}
	}
	else
		ARG = stitch2(o, ARG);
	ARGL = ft_strlen(ARG);
}

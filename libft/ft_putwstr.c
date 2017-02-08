/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:20:10 by dhuang            #+#    #+#             */
/*   Updated: 2017/02/06 22:20:10 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "includes/libft.h"

#define B ((unsigned char*)&wide)

static unsigned int	ft_wctounibig(unsigned int wide)
{
	unsigned char	tmp[4];

	*(int*)tmp = 0;
	tmp[3] = 128 | (63 & B[0]);
	tmp[2] = 128 | (B[0] >> 6) | (B[1] << 2 & 60);
	tmp[1] = 128 | (B[1] >> 4) | (B[2] << 4 & 48);
	tmp[0] = 240 | (B[2] >> 2);
	return (*(unsigned int*)tmp);
}

wchar_t				ft_wctouni(unsigned int wide)
{
	unsigned char	tmp[4];

	*(int*)tmp = 0;
	if (wide > 0xFFFF)
		return (ft_wctounibig(wide));
	else if (wide > 0x07FF)
	{
		tmp[2] = 128 | (63 & B[0]);
		tmp[1] = 128 | (B[0] >> 6) | (B[1] << 2 & 63);
		tmp[0] = 224 | (B[1] >> 4);
	}
	else if (wide > 0x00FF)
	{
		tmp[1] = 128 | (63 & B[0]);
		tmp[0] = 192 | (B[0] >> 6) | (B[1] << 2);
	}
	else if (wide > 0x007F)
	{
		tmp[1] = 128 | (63 & B[0]);
		tmp[0] = 192 | (B[0] >> 6);
	}
	else
		return (wide);
	return (*(unsigned int*)tmp);
}

void				ft_putwchar(unsigned int wc)
{
	wc = ft_wctouni(wc);
	write(1, &wc, 4);
}

void				ft_putwstr(unsigned int *wstr)
{
	unsigned int	tmp;

	while (*wstr)
	{
		tmp = ft_wctouni(*wstr++);
		write(1, &tmp, 4);
	}
}

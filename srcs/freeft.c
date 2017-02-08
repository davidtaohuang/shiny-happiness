	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 22:40:47 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/12 23:22:26 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	freeformat(t_format **format)
{
	if (*format)
	{
		if ((*format)->arg)
			ft_memdel((void**)&((*format)->arg));
		ft_memdel((void**)format);
	}
}

void	freeft(t_data **data)
{
	int		i;

	if (*data)
	{
		if ((*data)->str)
			ft_memdel((void**)&((*data)->str));
		if ((*data)->f)
		{
			i = 0;
			while (i < (*data)->nargs)
				freeformat(&((*data)->f[i++]));
			ft_memdel((void**)&((*data)->f));
		}
		ft_memdel((void**)data);
	}
}

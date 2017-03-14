/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsedbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:18:01 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/26 00:18:01 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parsedbl(t_format *flags, va_list *args)
{
	if (LEN == 3)
	{
		flags->arg = (long double*)ft_memalloc(sizeof(long double));
		*(long double*)(flags->arg) = va_arg(*args, long double);
		flags->argsize = sizeof(long double);
	}
	else
	{
		flags->arg = (double*)ft_memalloc(sizeof(double));
		*(double*)(flags->arg) = va_arg(*args, double);
		flags->argsize = sizeof(double);
	}
	if (!(flags->precision))
		flags->precision = 6;
	formatdbl(flags);
	padnum(flags);
}
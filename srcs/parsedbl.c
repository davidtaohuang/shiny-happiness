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

#define F (*pf)->f[i]
#define TYPE (*pf)->f[i]->conversion
#define LT tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length

void	parsedbl(t_data **pf, int i, va_list *args)
{
	if (LENGTH == 3)
	{
		F->arg = (long double*)ft_memalloc(sizeof(long double));
		*(long double*)(F->arg) = va_arg(*args, long double);
		F->argsize = sizeof(long double);
	}
	else
	{
		F->arg = (double*)ft_memalloc(sizeof(double));
		*(double*)(F->arg) = va_arg(*args, double);
		F->argsize = sizeof(double);
	}
	if (!((*pf)->f[i]->precision))
		(*pf)->f[i]->precision = 6;
}

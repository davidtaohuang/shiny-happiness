/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsezjt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:06:40 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/25 21:06:40 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define TYPE (*pf)->f[i]->conversion
#define LT ft_tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length

void	parsezjt(t_data **pf, int i, va_list *args)
{
	if (LT == 'u' || LT == 'd' || LT == 'i' || LT == 'o' || LT == 'x' ||
		LT == 'b')
	{
		if (LENGTH == 4)
		{
			F->arg = (size_t*)ft_memalloc(sizeof(size_t));
			*(size_t*)(F->arg) = va_arg(*args, size_t);
			F->argsize = sizeof(size_t);
		}
		else if (LENGTH == 5)
		{
			F->arg = (intmax_t*)ft_memalloc(sizeof(intmax_t));
			*(intmax_t*)(F->arg) = va_arg(*args, intmax_t);
			F->argsize = sizeof(intmax_t);
		}
		else if (LENGTH == 6)
		{
			F->arg = (ptrdiff_t*)ft_memalloc(sizeof(ptrdiff_t));
			*(ptrdiff_t*)(F->arg) = va_arg(*args, ptrdiff_t);
			F->argsize = sizeof(ptrdiff_t);
		}
	}
	else
		LENGTH = 0;
	parseswitch(pf, i, args);
}

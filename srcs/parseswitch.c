/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseswitch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 00:42:18 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/25 00:42:18 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define TYPE (*pf)->f[i]->conversion
#define LT ft_tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length

void	parsepct(t_data **pf, int i)
{
	F->arg = (char*)ft_memalloc(sizeof(char) * 2);
	*(char*)(F->arg) = '%';
	F->argsize = 1;
}

void	parseswitch(t_data **pf, int i, va_list *args)
{
	if (F->width < 0)
		F->width = va_arg(*args, unsigned int);
	if (F->precision < 0)
		F->precision = va_arg(*args, unsigned int);
	if (TYPE == 'p')
	{
		F->arg = va_arg(*args, void*);
		F->argsize = sizeof(void*);
	}
	else if (LENGTH > 3)
		parsezjt(pf, i, args);
	else if (LT == 'f' || LT == 'e' || LT == 'g' || LT == 'a')
		parsedbl(pf, i, args);
	else if (LT == 'c')
		parsechar(pf, i, args);
	else if (LT == 's')
		parsestr(pf, i, args);
	else if (LT == 'u' || LT == 'o' || LT == 'x' || LT == 'b')
		parseunum(pf, i, args);
	else if (LT == 'd' || LT == 'i')
		parsenum(pf, i, args);
	else if (LT == '%')
		parsepct(pf, i);
}

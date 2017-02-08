/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsestr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:15:33 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/25 21:15:33 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define TYPE (*pf)->f[i]->conversion
#define LT tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length

void	parsechar(t_data **pf, int i, va_list *args)
{
	if (LENGTH == 1 || TYPE == 'C')
	{
		F->arg = (wchar_t*)ft_memalloc(sizeof(wchar_t) * 2);
		*(wchar_t*)(F->arg) = va_arg(*args, wchar_t);
		F->argsize = sizeof(wchar_t);
	}
	else
	{
		F->arg = (char*)ft_memalloc(sizeof(char) * 2);
		*(char*)(F->arg) = va_arg(*args, int);
		F->argsize = sizeof(char);
	}
}

void	parsestr(t_data **pf, int i, va_list *args)
{
	if (LENGTH == 1 || TYPE == 'S')
	{
		F->arg = ft_wstrdup(va_arg(*args, wchar_t*));
		F->argsize = ft_wstrlen((wchar_t*)(F->arg));
	}
	else
	{
		F->arg = ft_strdup(va_arg(*args, char*));
		F->argsize = ft_strlen((char*)(F->arg));
	}
}

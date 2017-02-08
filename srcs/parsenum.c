/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsenum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:29:01 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/26 00:29:01 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define TYPE (*pf)->f[i]->conversion
#define LT tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length

void	parsesnum(t_data **pf, int i, va_list *args)
{
	if (LENGTH == -2)
	{
		F->arg = (long long*)ft_memalloc(sizeof(long long));
		*(long long*)(F->arg) = va_arg(*args, int);
		F->argsize = sizeof(char);
	}
	else if (LENGTH == -1)
	{
		F->arg = (long long*)ft_memalloc(sizeof(long long));
		*(long long*)(F->arg) = va_arg(*args, int);
		F->argsize = sizeof(short);
	}
}

void	parsenum(t_data **pf, int i, va_list *args)
{
	if (LENGTH == 1)
		TYPE = 'D';
	if (TYPE == 'D')
	{
		F->arg = (long long*)ft_memalloc(sizeof(long long));
		*(long long*)(F->arg) = va_arg(*args, long long);
		F->argsize = sizeof(long);
	}
	else if (LENGTH < 0)
		parsesnum(pf, i, args);
	else if (!LENGTH)
	{
		F->arg = (long long*)ft_memalloc(sizeof(long long));
		*(long long*)(F->arg) = va_arg(*args, int);
		F->argsize = sizeof(int);
	}
	else if (LENGTH == 2)
	{
		F->arg = (long long*)ft_memalloc(sizeof(long long));
		*(long long*)(F->arg) = va_arg(*args, long long);
		F->argsize = sizeof(long long);
	}
}

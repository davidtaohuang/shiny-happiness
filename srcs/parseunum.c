/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseunum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:51:02 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/26 00:51:02 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define TYPE (*pf)->f[i]->conversion
#define LT tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length

void	parsesunum(t_data **pf, int i, va_list *args)
{
	if (LENGTH == -2)
	{
		F->arg = (unsigned char*)ft_memalloc(sizeof(unsigned char));
		*(unsigned char*)(F->arg) = va_arg(*args, unsigned int);
		F->argsize = sizeof(char);
	}
	else if (LENGTH == -1)
	{
		F->arg = (unsigned short*)ft_memalloc(sizeof(unsigned short));
		*(unsigned short*)(F->arg) = va_arg(*args, unsigned int);
		F->argsize = sizeof(unsigned short);
	}
}

void	parseunum(t_data **pf, int i, va_list *args)
{
	if (LENGTH == 1)
		TYPE = 'U';
	if (TYPE == 'U' || TYPE == 'B' || TYPE == 'O')
	{
		F->arg = (unsigned long*)ft_memalloc(sizeof(unsigned long));
		*(unsigned long*)(F->arg) = va_arg(*args, unsigned long);
		F->argsize = sizeof(unsigned long);
	}
	else if (LENGTH < 0)
		parsesunum(pf, i, args);
	else if (!LENGTH)
	{
		F->arg = (unsigned int*)ft_memalloc(sizeof(unsigned int));
		*(unsigned int*)(F->arg) = va_arg(*args, unsigned int);
		F->argsize = sizeof(unsigned int);
	}
	else if (LENGTH == 2)
	{
		F->arg = (unsigned long long*)ft_memalloc(sizeof(unsigned long long));
		*(unsigned long long*)(F->arg) = va_arg(*args, unsigned long long);
		F->argsize = sizeof(unsigned long long);
	}
}

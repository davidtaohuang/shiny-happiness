/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 18:56:20 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/12 22:39:37 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print(char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (str[i] > 127)
		{
			ft_putwchar(str[i]);
			i += 4;
		}
		else
			ft_putchar(str[i++]);
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list *args;
	t_data	*pf;
	int		chars;

	if (format)
	{
		pf = (t_data*)ft_memalloc(sizeof(t_data));
		if (!pf)
			return (0);
		pf->strlen = ft_strlen(format);
		pf->str = (char*)ft_memalloc(sizeof(char) * (pf->strlen + 1));
		ft_memmove(pf->str, format, pf->strlen);
		pf->nargs = numargs(&pf);
		args = (va_list*)ft_memalloc(sizeof(va_list));
		va_start(*args, format);
		datasetup(&pf, args);
		va_end(*args);
		ft_memdel((void**)&args);
		typeswitch(&pf);
		print(pf->str, pf->strlen);
		chars = pf->strlen;		
		freeft(&pf);
		return (chars);
	}
	return (0);
}

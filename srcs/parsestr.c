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

int			ft_charlen(unsigned char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] < 0x80)
			i++;
		else if (str[i] < 0xe0)
			i += 2;
		else if (str[i] < 0xf0)
			i += 3;
		else
			i += 4;
		len++;
	}
	return (len);
}

static void	parsewide(t_format *flags, va_list *args)
{
	wchar_t	*tmp;

	if (LT == 'c')
	{
		tmp = (wchar_t*)ft_memalloc(sizeof(wchar_t) * 2);
		*tmp = va_arg(*args, wchar_t);
		flags->arg = ft_wstouni(tmp);
		flags->argsize = 1;
		flags->bytelen = ft_strlen(flags->arg);
		ft_memdel((void**)&tmp);
	}
	else
	{
		tmp = va_arg(*args, wchar_t*);
		flags->arg = ft_wstouni(tmp);
		flags->argsize = ft_wstrlen(tmp);
		flags->bytelen = ft_strlen(flags->arg);
	}
}

void		parsechar(t_format *flags, va_list *args)
{
	if (LEN == 1 || TYPE == 'C')
		parsewide(flags, args);
	else
	{
		flags->arg = (char*)ft_memalloc(sizeof(char) * 2);
		*(char*)(flags->arg) = va_arg(*args, int);
		flags->argsize = sizeof(char);
		// if (((char*)(flags->arg))[0] == '\0')
		// 	pf->nc++;
	}
	padcs(flags);
}

void		parsestr(t_format *flags, va_list *args)
{
	char	*tmp;

	if (LEN == 1 || TYPE == 'S')
		parsewide(flags, args);
	else
	{
		tmp = va_arg(*args, char*);
		if (tmp)
		{
			flags->arg = ft_strdup(tmp);
			flags->argsize = ft_strlen((char*)(flags->arg));
		}
		else if (!tmp && P != 0)
		{
			flags->arg = ft_strdup("(null)");
			flags->argsize = 6;
		}
		if (flags->negp && P < ARGL)
			P = ARGL;
	}
	padcs(flags);
}
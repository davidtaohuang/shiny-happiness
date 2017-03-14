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

char	*g_validconv = "diouxXDOUeEfFgGaACcSspn%b";
char	*g_validflag = "#0- +\'*123456789.hlLjtzq";

static void	findformat(t_data *pf, va_list *args)
{
	char		*tmp;
	int			len;
	t_format	*flags;

	tmp = pf->old;
	len = ft_strchr(tmp, '%') - tmp;
	if (len < 0)
		len = ft_strchr(tmp, '\0') - tmp;
	if (len)
	{
		insertformat(pf, len);
		return ;
	}
	tmp++;
	while (*tmp && ft_strchr(g_validflag, *tmp))
		tmp++;
	flags = (t_format*)ft_memalloc(sizeof(t_format));
	flags->conversion = *tmp;
	datasetup(flags, pf->old, args);
	parseswitch(flags, args, pf);
	cutformat(pf, flags);
	ft_memdel((void**)&flags);
}

static void	ft_pfstr(t_data pf)
{
	int		i;

	if (pf.str)
	{
		i = 0;
		while (i++ < pf.strlen)
			write(1, pf.str++, 1);
	}
}

int			ft_printf(const char *restrict format, ...)
{
	va_list args;
	t_data	pf;

	if (format)
	{
		ft_bzero(&pf, sizeof(pf));
		pf.strlen = 0;
		pf.str = ft_strnew(0);
		pf.old = ft_strdup(format);
		va_start(args, format);
		while (*(pf.old))
			findformat(&pf, &args);
		va_end(args);
		// ft_memdel((void**)&args);
		// ft_putstr(pf.str);
		ft_pfstr(pf);
		ft_memdel((void**)&(pf.str));
		ft_memdel((void**)&(pf.old));
		return (pf.strlen);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:46:45 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/30 21:46:45 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	insertformat(t_data *pf, int len)
{
	char	*t1;
	int		end;

	t1 = ft_strsub(pf->old, 0, len);
	pf->str = ft_strjoinreplace(pf->str, t1);
	ft_memdel((void**)&t1);
	if (pf->old[len])
	{
		end = ft_strchr(pf->old, '\0') - pf->old;
		t1 = ft_strsub(pf->old, len, end);
		ft_memdel((void**)&(pf->old));
		pf->old = t1;
	}
	else
	{
		ft_memdel((void**)&(pf->old));
		pf->old = ft_strnew(0);
	}
	pf->strlen += len;
}

void	cutformat(t_data *pf, t_format *flags)
{
	char	*t1;
	char	*t2;
	int		len;

	t1 = ft_strchr(pf->old + 1, TYPE) + 1;
	len = ft_strlen(t1);
	t2 = ft_strsub(t1, 0, len);
	ft_memdel((void**)&(pf->old));
	pf->old = t2;
	if (TYPE != 'n')
	{
		if (*((char*)ARG) || LT == 'c')
			pf->strlen += flags->argsize;
		pf->str = ft_strjoinreplace(pf->str, ARG);
		ft_memdel((void**)&(ARG));
	}
}

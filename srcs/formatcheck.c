/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 19:13:36 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/11 16:26:36 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define STR (*pf)->str
#define INDEX (*pf)->index
#define ARG (*pf)->f[i]->arg
#define TYPE (*pf)->f[i]->conversion
#define LT tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length

// void	doublepercent(t_data **pf)
// {
// 	int		i;
// 	char	*f;
// 	char	*t1;
// 	char	*t2;

// 	f = STR;
// 	i = 0;
// 	while ((f = ft_strchr(f, '%')))
// 	{
// 		if (*f == '%' && (f + 1) == '%')
// 		{
// 			t1 = ft_strsub(STR, 0, f - STR);
// 			f++;
// 			t2 = ft_strsub(f, 0, STRE - f);
// 			ft_memdel((void**)&STR);
// 			STR = ft_strjoinreplace(t1, t2);
// 			ft_memdel((void**)&t2);
// 			f = (*pf)->str;
// 			i = 0;
// 			(*pf)->strlen = ft_strlen((*pf)->str);
// 		}
// 		else
// 			f++;
// 	}
// }

void	numargs3(t_data **pf)
{
	char	*tmp;

	tmp = &(STR[INDEX]);
	if (*tmp == 'h')
	{
		tmp++;
		if (*tmp == 'h')
			tmp++;
	}
	else if (*tmp == 'l')
	{
		tmp++;
		if (*tmp == 'l')
			tmp++;
	}
	else
		tmp++;
	tmp++;
	INDEX = tmp - STR;
}

void	numargs2(t_data **pf)
{
	char	*tmp;

	tmp = &(STR[INDEX]);
	if (*tmp == '.')
	{
		tmp++;
		if (*tmp == '*')
			tmp++;
		while (*tmp >= '0' &&  *tmp <= '9')
			tmp++;
	}
	INDEX = tmp - STR;
	numargs3(pf);
}

int		numargs(t_data **pf)
{
	int		nargs;
	char	*tmp;
	
	tmp = (*pf)->str;
	nargs = 0;
	while ((tmp = (ft_strchr(tmp, '%'))))
	{
		nargs++;
		while (*tmp == '-' ||  *tmp == '+' || *tmp == ' ' || *tmp == '0'
		|| *tmp == '#')
			tmp++;
		if ((*tmp >= '0' &&  *tmp <= '9') || *tmp == '*')
		{
			tmp++;
			while (*tmp >= '0' &&  *tmp <= '9')
				tmp++;
		}
		INDEX = tmp - STR;
		numargs2(pf);
		tmp = &(STR[INDEX]);
	}
	INDEX = 0;
	return (nargs);
}

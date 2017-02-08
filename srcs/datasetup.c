/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datasetup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:39:59 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/24 18:39:59 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define TYPE (*pf)->f[i]->conversion
#define LTYPE tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length
#define FGP (*pf)->f[i]->flagplus
#define FGS (*pf)->f[i]->flagspace
#define FGN (*pf)->f[i]->flagpound
#define FGM (*pf)->f[i]->flagminus
#define FGZ (*pf)->f[i]->flagzero
#define INDEX (*pf)->strindex
#define STR (*pf)->str
#define SLEN (*pf)->strlen

static void	loadformat4(t_data **pf, int i, char *tmp)
{
	if (*tmp == 'L')
		F->length = 3;
	else if (*tmp == 'j')
		F->length = 4;
	else if (*tmp == 'z')
		F->length = 5;
	else if (*tmp == 't')
		F->length = 6;
}

static void	loadformat3(t_data **pf, int i, char *tmp)
{
	if (*tmp == 'h')
	{
		F->length--;
		tmp++;
		if (*tmp == 'h')
		{
			F->length--;
			tmp++;
		}
	}
	else if (*tmp == 'l')
	{
		F->length++;
		tmp++;
		if (*tmp == 'l')
		{
			F->length++;
			tmp++;
		}
	}
	else if (*tmp == 'L' || *tmp == 'j' || *tmp == 'z' || *tmp == 't')
		loadformat4(pf, i, tmp++);
	F->conversion = *tmp;
}

static void	loadformat2(t_data **pf, int i, char *tmp)
{
	if (*tmp >= '0' &&  *tmp <= '9')
	{
		F->width = ft_atoi(tmp);
		while (*tmp >= '0' &&  *tmp <= '9')
			tmp++;
	}
	else if (*tmp == '*')
	{
		F->width = -1;
		tmp++;
	}
	if (*tmp == '.')
	{
		tmp++;
		if (*tmp == '*')
		{
			F->precision = -1;
			tmp++;
		}
		else
			F->precision = ft_atoi(tmp);
		while (*tmp >= '0' &&  *tmp <= '9')
			tmp++;
	}
	loadformat3(pf, i, tmp);
}

/* Didn't initially realize that multiple flages are permitted,
** using bitwise operators to keep track of flags now.
** '-' corresponds to 1.
** '+' corresponds to 2.
** ' ' corresponds to 4.
** '0' corresponds to 8.
** '#' corresponds to 16.
**
** Unfortunately, flags are codependent, and order doesn't matter?
**
** 1. Either '+' or ' ' but not both.
** 2.
*/

static void	loadformat1(t_data **pf, int i, char *tmp)
{
	F->index = i;
	tmp++;
	while (*tmp == '-' ||  *tmp == '+' || *tmp == ' ' || *tmp == '0'
		|| *tmp == '#')
	{
		if (*tmp == '-')
			FGM = 1;
		else if (*tmp == '+')
			FGP = 1;
		else if (*tmp == ' ')
			FGS = 1;
		else if (*tmp == '0')
			FGZ = 1;
		else
			FGN = 1;
		tmp++;
	}
	if (FGM)
		FGZ = 0;
	if (FGP)
		FGS = 0;
	loadformat2(pf, i, tmp);
}

void	datasetup(t_data **pf, va_list *args)
{
	int		i;
	char	*tmp;

	(*pf)->f = (t_format**)ft_memalloc(sizeof(t_format*) * (*pf)->nargs);
	i = 0;
	tmp = (*pf)->str;
	while ((tmp = ft_strchr(tmp, '%')))
	{
		(*pf)->f[i] = (t_format*)ft_memalloc(sizeof(t_format));
		(*pf)->f[i]->index = i;
		loadformat1(pf, i, tmp);
		parseswitch(pf, i, args);
		tmp = ft_strchr(tmp, TYPE);
		tmp++;
		i++;
	}
}

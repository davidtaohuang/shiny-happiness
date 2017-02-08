/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:46:03 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/30 20:46:03 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define ARG (*pf)->f[i]->arg
#define ARGL (*pf)->f[i]->argsize
#define FGP (*pf)->f[i]->flagplus
#define FGS (*pf)->f[i]->flagspace
#define FGN (*pf)->f[i]->flagpound
#define FGM (*pf)->f[i]->flagminus
#define FGZ (*pf)->f[i]->flagzero
#define TYPE (*pf)->f[i]->conversion
#define LT ft_tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length

void	formatnum(t_data **pf, int i)
{
	char		*numstr;

	numstr = ft_itoa(*(long long*)ARG);
	ft_memdel((void**)&ARG);
	ARG = numstr;
	ARGL = ft_strlen(ARG);
}

void	formatunum(t_data **pf, int i)
{
	char		*numstr;
	int			j;

	if (LT == 'u')
		numstr = ft_itoabase(*(unsigned long long*)ARG, 10);
	else if (LT == 'o')
		numstr = ft_itoabase(*(unsigned long long*)ARG, 8);
	else if (LT == 'x' || TYPE == 'p')
		numstr = ft_itoabase(*(unsigned long long*)ARG, 16);
	else if (LT == 'b')
		numstr = ft_itoabase(*(unsigned long long*)ARG, 2);
	if (TYPE == 'X' || TYPE == 'p')
	{
		j = 0;
		while (numstr[j])
		{
			numstr[j] = ft_tolower(numstr[j]);
			j++;
		}
	}
	ft_memdel((void**)&ARG);
	ARG = numstr;
	ARGL = ft_strlen(ARG);
	FGP = 0;
	FGS = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeswitch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:33:58 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/23 22:33:58 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define STR (*pf)->str
#define INDEX (*pf)->index
#define ARG (*pf)->f[i]->arg
#define ARGL (*pf)->f[i]->argsize
#define WO (*pf)->woffset
#define TYPE (*pf)->f[i]->conversion
#define LT ft_tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length

void	formatn(t_data **pf, int i)
{
	ARG = ft_itoa(INDEX - (3 * WO));
	ARGL = ft_strlen(ARG);
}

void	typeswitch(t_data **pf)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = STR;
	while ((tmp = ft_strchr(tmp, '%')))
	{
		INDEX = tmp - STR;
		if (TYPE == 'n')
			formatn(pf, i);
		else if (LT == 'f' || LT == 'e' || LT == 'g' || LT == 'a')
			formatdbl(pf, i);
		else if (LT == 'd' || LT == 'i')
			formatnum(pf, i);
		else
			formatunum(pf, i);
		if (TYPE != 'n' && TYPE != '%')
			padswitch(pf, i);
		insertformat(pf, i);
		tmp = &STR[INDEX];
		i++;
	}
}

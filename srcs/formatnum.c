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

void	formatnum(t_format *flags)
{
	char		*numstr;

	if (LEN == -2)
		numstr = ft_itoa(*(char*)ARG);
	else if (LEN == -1)
		numstr = ft_itoa(*(short*)ARG);
	else if (LEN == 0)
		numstr = ft_itoa(*(int*)ARG);
	else
		numstr = ft_itoa(*(long*)ARG);
	ft_memdel((void**)&ARG);
	ARG = numstr;
	ARGL = ft_strlen(ARG);
}

static void	ft_alllower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

void	formatunum(t_format *flags)
{
	char		*numstr;

	if (LT == 'u')
		numstr = ft_itoabase(*(unsigned long long*)ARG, 10);
	else if (LT == 'o')
		numstr = ft_itoabase(*(unsigned long long*)ARG, 8);
	else if (LT == 'x' || LT == 'p')
		numstr = ft_itoabase(*(unsigned long long*)ARG, 16);
	else // (LT == 'b')
		numstr = ft_itoabase(*(unsigned long long*)ARG, 2);
	if (TYPE == 'x' || TYPE == 'p')
		ft_alllower(numstr);
	ft_memdel((void**)&ARG);
	ARG = numstr;
	ARGL = ft_strlen(ARG);
	FGP = 0;
	FGS = 0;
}

void	formatzjt(t_format *flags)
{
	if (LT == 'i' || LT == 'd')
		formatnum(flags);
	else
		formatunum(flags);
	padnum(flags);
}

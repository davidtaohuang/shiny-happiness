/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padswitch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:16:19 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/31 14:16:19 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define ARG (*pf)->f[i]->arg
#define ARGL (*pf)->f[i]->argsize
#define FG (*pf)->f[i]->flag
#define W (*pf)->f[i]->width
#define P (*pf)->f[i]->precision
#define TP (*pf)->f[i]->conversion
#define LT ft_tolower((*pf)->f[i]->conversion)
#define LEN (*pf)->f[i]->length

void	padswitch(t_data **pf, int i)
{
	if (LT == 's' || LT == 'c')
		padcs(pf, i);
	else if (LT == 'f' || LT == 'g' || LT == 'e' || LT == 'a')
		padnum(pf, i);
	else
		padnum(pf, i);
}

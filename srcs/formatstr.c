/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:01:08 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/31 14:01:08 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define F pf->f[i]
#define ARG pf->f[i]->arg
#define ARGL pf->f[i]->argsize
#define TYPE pf->f[i]->conversion
#define LT tolower(pf->f[i]->conversion)
#define LENGTH pf->f[i]->length

void	formatstr(t_data **pf, int i)
{
	char	*str;

	

}
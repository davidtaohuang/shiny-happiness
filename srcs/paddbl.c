/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paddbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:21:14 by dhuang            #+#    #+#             */
/*   Updated: 2017/02/06 17:21:14 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../includes/ft_printf.h"

#define F (*pf)->f[i]
#define SA (char*)(*pf)->f[i]->arg[0]
#define ARG (*pf)->f[i]->arg
#define ARGL (*pf)->f[i]->argsize
#define FGP (*pf)->f[i]->flagplus
#define FGS (*pf)->f[i]->flagspace
#define FGN (*pf)->f[i]->flagpound
#define FGM (*pf)->f[i]->flagminus
#define FGZ (*pf)->f[i]->flagzero
#define W (*pf)->f[i]->width
#define P (*pf)->f[i]->precision
#define TP (*pf)->f[i]->conversion
#define LT tolower((*pf)->f[i]->conversion)
#define LEN (*pf)->f[i]->length


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

#define F (*pf)->f[i]
#define STR (*pf)->str
#define STRE &((*pf)->str[(*pf)->strlen])
#define ARG (*pf)->f[i]->arg
#define TYPE (*pf)->f[i]->conversion
#define LT tolower((*pf)->f[i]->conversion)
#define LENGTH (*pf)->f[i]->length

void	insertformat(t_data **pf, int i)
{
	char	*fs;
	char	*fe;
	char	*t1;
	char	*t2;

	fs = ft_strchr(STR, '%');
	while (*(fs + 1) == '%')
		fs = ft_strchr(fs, '%');
	t1 = ft_strsub(STR, 0, fs - STR);
	fe = ft_strchr(fs, TYPE);
	t2 = ft_strsub(fe + 1, 0, STRE - fe);
	ft_memdel((void**)&((*pf)->str));
	t1 = ft_strjoinreplace(t1, (char*)ARG);
	STR = ft_strjoinreplace(t1, t2);
	ft_memdel((void**)&t2);
	(*pf)->strlen = ft_strlen((*pf)->str);
}

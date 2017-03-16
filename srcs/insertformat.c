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

char	*ft_pfstrnj(const char *s1, size_t len1, const char *s2, size_t len2)
{
	char	*s;
	size_t	n;
	size_t	i;
	size_t	j;

	n = (size_t)(len1 + len2);
	s = ft_strnew(n);
	if (!s)
		return (s);
	i = 0;
	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		s[i++] = s2[j++];
	ft_memdel((void**)&s1);
	return (s);
}

void	insertformat(t_data *pf, int len)
{
	char	*t1;
	int		end;

	t1 = ft_strsub(pf->old, 0, len);
	pf->str = ft_pfstrnj(STR, BLEN, t1, len);
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
	CLEN += len;
	BLEN += len;
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
		// if (!*((char*)ARG) && LT == 'c')
		//  	pf->nc += 1;
		pf->str = ft_pfstrnj(pf->str, BLEN, ARG, FBLEN);
		if (ARG && (*((char*)ARG) || LT == 'c'))
		{
			CLEN += ARGL;
			BLEN += (((LT == 'c' || LT == 's') && LEN == 1) ? FBLEN : ARGL);
		}
		// pf->str = ft_strjoinreplace(pf->str, ARG);
		ft_memdel((void**)&(ARG));
	}
}

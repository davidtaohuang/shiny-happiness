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

char	*g_numconv = "diouxXDOUeEfFgGaAp";

static int	findhhll(t_format *flags, char *tmp, int len, int i)
{
	if (tmp[i] == 'h')
	{
		if (i < len - 1 && tmp[i + 1] == 'h')
		{
			flags->length = -2;
			return (i + 1);
		}
		else
			flags->length = -1;
	}
	else
	{
		if (i < len - 1 && tmp[i + 1] == 'l')
		{
			flags->length = 2;
			return (i + 1);
		}
		else
			flags->length = 1;
	}
	return (i);
}

static void	findlength(t_format *flags, char *tmp, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tmp[i] == 'h' && flags->length <= 0)
			i = findhhll(flags, tmp, len, i);
		else if (tmp[i] == 'l')
			i = findhhll(flags, tmp, len, i);
		else if (tmp[i] == 'L')
			flags->length = 3;
		else if (tmp[i] == 'j')
			flags->length = 4;
		else if (tmp[i] == 'z')
			flags->length = 5;
		else if (tmp[i] == 't')
			flags->length = 6;
		i++;
	}
}

// static void	findwp(t_format *flags, char *tmp, int len, va_list *args)
// {
// 	int		i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		if (ft_isdigit(tmp[i]) && tmp[i] != '0')
// 		{
// 			if (i > 0 && tmp[i - 1] == '.')
// 				flags->precision = ft_atoi(tmp + i);
// 			else
// 				flags->width = ft_atoi(tmp + i);
// 			while (ft_isdigit(tmp[i]))
// 				i++;
// 		}
// 		else if (tmp[i] == '*')
// 		{
// 			if (i > 0 && tmp[i - 1] == '.')
// 				flags->precision = va_arg(*args, int);
// 			else
// 				flags->width = va_arg(*args, int);
// 			i++;
// 		}
// 		else
// 			i++;
// 	}
// }

static void	findw(t_format *flags, char *tmp, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (ft_isdigit(tmp[i]) && tmp[i] != '0')
		{
			if (tmp[i - 1] != '.')
				flags->width = ft_atoi(tmp + i);
			while (ft_isdigit(tmp[i]))
				i++;
		}
		else
			i++;
	}
}

static void	findp(t_format *flags, char *tmp, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tmp[i] == '.')
		{
			flags->precision = 0;
			while (!ft_isdigit(tmp[i]) && i < len)
				i++;
			if (ft_isdigit(tmp[i]))
			{
				flags->precision = ft_atoi(tmp + i);
				while (ft_isdigit(tmp[i]))
					i++;
			}
		}
		else
			i++;
	}
}

static void	findast(t_format *flags, char *tmp, int len, va_list *args)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tmp[i] == '*')
		{
			if (i > 0 && tmp[i - 1] == '.')
			{
				flags->precision = va_arg(*args, int);
				if (flags->precision < 0)
				{
					flags->negp = 1;
					flags->precision = 1;
				}
			}
			else
			{
				flags->width = va_arg(*args, int);
				// flags->flagzero = 0;
			}
			i++;
		}
		else
			i++;
	}
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

static void	findflags(t_format *flags, char *tmp, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tmp[i] == '-')
			flags->flagminus = 1;
		else if (tmp[i] == '+')
			flags->flagplus = 1;
		else if (tmp[i] == ' ')
			flags->flagspace = 1;
		else if (tmp[i] == '0' && tmp[i - 1] != '.' && !ft_isdigit(tmp[i - 1]))
			flags->flagzero = 1;
		else if (tmp[i] == '#')
			flags->flagpound = 1;
		i++;
	}
}

void	datasetup(t_format *flags, char *format, va_list *args)
{
	int			len;
	char		*tmp;
	
	tmp = format;
	tmp++;
	flags->precision = -1;
	len = ft_strchr(tmp, TYPE) - tmp;
	findflags(flags, tmp, len);
	findw(flags, tmp, len);
	findp(flags, tmp, len);
	findast(flags, tmp, len, args);
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->flagminus = 1;
	}
	if (flags->flagminus || flags->flagspace || (!P && ft_strchr(g_numconv, TYPE)))
		flags->flagzero = 0;
	if (flags->flagplus)
		flags->flagspace = 0;
	findlength(flags, tmp, len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 22:02:41 by dhuang            #+#    #+#             */
/*   Updated: 2017/01/12 20:01:02 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include "../libft/includes/libft.h"

typedef struct	s_format
{
	int			index;
	char		flagzero;
	char		flagplus;
	char		flagminus;
	char		flagpound;
	char		flagspace;
	int			width;
	int			precision;
	int			length;
	char		conversion;
	void		*arg;
	int			argsize;
}				t_format;

typedef struct	s_data
{
	int			nargs;
	char		*str;
	int			index;
	int			strlen;
	int			woffset;
	t_format	**f;
}				t_data;

void			datasetup(t_data **pf, va_list *args);
int				ft_printf(const char *restrict format, ...);
int				numargs(t_data **pf);
void			freeft(t_data **pf);
void			typeswitch(t_data **pf);
void			parseswitch(t_data **pf, int i, va_list *args);
void			parsezjt(t_data **pf, int i, va_list *args);
void			parsedbl(t_data **pf, int i, va_list *args);
void			parsechar(t_data **pf, int i, va_list *args);
void			parsestr(t_data **pf, int i, va_list *args);
void			parsenum(t_data **pf, int i, va_list *args);
void			parseunum(t_data **pf, int i, va_list *args);
void			formatdbl(t_data **pf, int i);
void			formatnum(t_data **pf, int i);
void			formatunum(t_data **pf, int i);
void			padswitch(t_data **pf, int i);
void			insertformat(t_data **pf, int i);
void			padcs(t_data **pf, int i);
void			padnum(t_data **pf, int i);
int				ft_dtoa(double n, int p, char *frac);
char			*adddigit(char *dec);
int				rounding(char *dec, int i);

#endif

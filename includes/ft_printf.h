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
# include <wchar.h>
# include "../libft/includes/libft.h"

typedef struct	s_format
{
	//int			index;
	char		flagzero;
	char		flagplus;
	char		flagminus;
	char		flagpound;
	char		flagspace;
	char		negp;
	char		wast;
	int			width;
	int			wl;
	int			precision;
	int			pl;
	int			length;
	char		conversion;
	void		*arg;
	int			argsize;
	int			bytelen;
}				t_format;

typedef struct	s_data
{
	char		*str;
	char		*old;
	int			charlen;
	int			bytelen;
}				t_data;

#define STR pf->str
#define CLEN pf->charlen
#define BLEN pf->bytelen
#define TYPE flags->conversion
#define LT ft_tolower(flags->conversion)
#define LEN flags->length
#define ARG flags->arg
#define ARGL flags->argsize
#define FBLEN flags->bytelen
#define FGP flags->flagplus
#define FGS flags->flagspace
#define FGN flags->flagpound
#define FGM flags->flagminus
#define FGZ flags->flagzero
#define P flags->precision
#define W flags->width
#define SA ((char*)flags->arg)[0]

int				ft_printf(const char *restrict format, ...);
void			datasetup(t_format *flags, char *format, va_list *args);
void			insertformat(t_data *pf, int len);
char			*ft_pfstrnj(const char *s1, size_t len1, const char *s2, size_t len2);
void			cutformat(t_data *pf, t_format *flags);
void			parseswitch(t_format *flags, va_list *args, t_data *pf);

void			parsezjt(t_format *flags, va_list *args, t_data *pf);
void			parsedbl(t_format *flags, va_list *args);
void			parsenum(t_format *flags, va_list *args);
void			parsechar(t_format *flags, va_list *args);
void			parsestr(t_format *flags, va_list *args);
void			parseunum(t_format *flags, va_list *args);

void			formatdbl(t_format *flags);
void			formatnum(t_format *flags);
void			formatunum(t_format *flags);
void			formatzjt(t_format *flags);

void			padcs(t_format *flags);
void			padnum(t_format *flags);
void			padhex(t_format *flags);
void			padoct(t_format *flags);
void			padgen(t_format *flags);

int				ft_dtoa(double n, int p, char *frac);
char			*adddigit(char *dec);
int				rounding(char *dec, int i);
void			*stitch2(char *s1, char *s2);
void			*stitch3(char *s1, char *s2, char *s3);

#endif

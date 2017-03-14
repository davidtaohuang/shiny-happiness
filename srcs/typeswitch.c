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

// void	typeswitch(t_data **pf)
// {
// 	char	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = STR;
// 	while ((tmp = ft_strchr(tmp, '%')))
// 	{
// 		INDEX = tmp - STR;
// 		else if (LT == 'f' || LT == 'e' || LT == 'g' || LT == 'a')
// 			formatdbl(pf, i);
// 		else if (LT == 'd' || LT == 'i')
// 			formatnum(pf, i);
// 		else if (TYPE && LT != 'c' && LT != 's' && TYPE != '%')
// 			formatunum(pf, i);
// 		else if (!TYPE)
// 			formaterr(pf, i);
// 		if (TYPE != 'n')
// 			padswitch(pf, i);
// 		insertformat(pf, i);
// 		tmp = &STR[INDEX] + ARGL;
// 		i++;

// 	}
// }

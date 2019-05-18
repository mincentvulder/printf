/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkflags.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 12:36:26 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/18 19:11:10 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

int		ft_checkperc(t_struct *val)
{
	if (val->fmt[val->i] == '%')
	{
		val->buf[val->bi] = '%';
		return (1);
	}
	return (0);
}

void	ft_checkflagsif(t_struct *val)
{
	if (val->fmt[val->i] == '-')
		val->flagmin = 1;
	else if (val->fmt[val->i] == '+')
		val->flagplus = 1;
	else if (val->fmt[val->i] == ' ')
		val->flagspace = 1;
	else if (val->fmt[val->i] == '#')
		val->flaghasj = 1;
	else if (val->fmt[val->i] == '0')
		val->flagnull = 1;
}

void	ft_checkflags(t_struct *val)
{
	while (val->fmt[val->i] == '-' || val->fmt[val->i] == '+'
			|| val->fmt[val->i] == ' ' || val->fmt[val->i] == '#'
			|| val->fmt[val->i] == '0')
	{
		ft_checkflagsif(val);
		val->i++;
	}
}

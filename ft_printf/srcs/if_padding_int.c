/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_padding_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:47:48 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 17:01:51 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void		apply_left(t_option *options, int c, int len_str, char *str)
{
	while (options->width > len_str)
	{
		write(1, &c, 1);
		options->nprinted++;
		options->width--;
	}
	ft_putstr(str);
	if (options->sign == NEGATIVE)
	{
		if (options->precision != -1)
			options->nprinted += len_str;
		else
			options->nprinted += len_str - 1;
	}
	else
		options->nprinted += len_str;
}

void		if_width_less(char *str, t_option *options)
{
	ft_putstr(str);
	options->nprinted += ft_strlen(str);
}

int			if_no_prec_int(t_option *options, int c)
{
	options->nprinted += 1;
	c = ' ';
	return (c);
}

void		left_padding_int(char *str, t_option *options, int c)
{
	int len_str;
	int prectf;

	prectf = options->precisiontf;
	len_str = ft_strlen(str);
	if (options->width <= len_str)
		if_width_less(str, options);
	else
	{
		if (options->sign == NEGATIVE)
		{
			if (c == '0' && options->precision == -1 && prectf != -1)
			{
				options->nprinted += write(1, "-", 1);
				str += 1;
			}
			else if (options->precision == -1)
				c = if_no_prec_int(options, c);
			else
				c = ' ';
		}
		else if (c == '0' && options->precision > -1 && prectf != -1)
			c = ' ';
		apply_left(options, c, len_str, str);
	}
}

void		right_padding_int(char *str, t_option *options, int c)
{
	c = ' ';
	if (options->width <= ft_strlen(str))
	{
		ft_putstr(str);
		options->nprinted += ft_strlen(str);
	}
	else
	{
		if (options->width > ft_strlen(str))
		{
			ft_putstr(str);
			options->nprinted += ft_strlen(str);
			while (options->width > ft_strlen(str))
			{
				write(1, &c, 1);
				options->nprinted++;
				options->width--;
			}
		}
	}
}

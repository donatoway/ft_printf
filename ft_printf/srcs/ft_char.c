/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:32:00 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 16:35:24 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void	ft_char(t_option *options, va_list args)
{
	int c;
	int y;

	c = va_arg(args, int);
	if (options->zero == 1)
		y = '0';
	else
		y = ' ';
	if (options->minus == 0)
		left_padding_char(c, options, y);
	else
		right_padding_char(c, options, y);
}

void	left_padding_char(int c, t_option *options, int y)
{
	int width;

	width = options->width - 1;
	if (options->width <= 1)
		options->nprinted += write(1, &c, 1);
	else
	{
		while (width--)
			options->nprinted += write(1, &y, 1);
		options->nprinted += write(1, &c, 1);
	}
}

void	right_padding_char(int c, t_option *options, int y)
{
	y = ' ';
	if (options->width <= 1)
		options->nprinted += write(1, &c, 1);
	else
	{
		options->nprinted += write(1, &c, 1);
		while (options->width > 1)
		{
			options->nprinted += write(1, &y, 1);
			options->width--;
		}
	}
}

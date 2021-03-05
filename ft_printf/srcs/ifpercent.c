/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpercent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:51:55 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 14:56:42 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void	if_percent(t_option *options)
{
	int c;

	if (options->zero == 1)
		c = '0';
	else
		c = ' ';
	if (options->minus == 0)
		left_padding_percent(c, options);
	else
		right_padding_percent(c, options);
}

void	left_padding_percent(int c, t_option *options)
{
	int width;

	width = options->width - 1;
	if (width > 1)
	{
		while (width--)
			options->nprinted += write(1, &c, 1);
		options->nprinted += write(1, "%", 1);
	}
	else
		options->nprinted += write(1, "%", 1);
}

void	right_padding_percent(int c, t_option *options)
{
	int width;

	c = ' ';
	width = options->width - 1;
	if (width > 1)
	{
		options->nprinted += write(1, "%", 1);
		while (width--)
			options->nprinted += write(1, &c, 1);
	}
	else
		options->nprinted += write(1, "%", 1);
}

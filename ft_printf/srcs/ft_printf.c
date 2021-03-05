/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:56:58 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/14 17:09:35 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void	analyze_coversions(char *format, va_list args, t_option *options)
{
	int position;

	position = options->len + 1;
	if (format[position] == '%')
	{
		write(1, "%", 1);
		options->nprinted++;
		options->len += 2;
	}
	else
	{
		set_flags(format, options);
		set_width(format, args, options);
		set_precision(format, args, options);
		if (format[options->len + 1] == '\0')
			options->len += 1;
		else
			set_conversion(format, options, args);
	}
}

void	analyze_char(char *format, va_list args, t_option *options)
{
	int position;

	position = options->len;
	if (format[position] != '%')
	{
		write(1, &format[position], 1);
		options->nprinted++;
		options->len++;
	}
	else
	{
		analyze_coversions(format, args, options);
	}
}

int		ft_printf(const char *format, ...)
{
	t_option	*options;
	va_list		args;

	if (!(options = (t_option*)malloc(sizeof(t_option))))
		return (0);
	va_start(args, format);
	setzero_all(options);
	if (!format[0])
	{
		write(1, "", 0);
		return (0);
	}
	if (format[0] == '%' && ft_strlen(format) == 1)
		return (0);
	while (format[options->len])
	{
		setzero(options);
		analyze_char((char*)format, args, options);
	}
	va_end(args);
	free(options);
	return (options->nprinted);
}

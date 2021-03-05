/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:13:56 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/14 17:08:58 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void		set_flags(char *format, t_option *options)
{
	while (!(ft_strchr("cspdiuxX%123456789.*", format[options->len + 1])))
	{
		if (ft_strchr("-+0# ", format[options->len + 1]))
		{
			if (format[options->len + 1] == '-')
				options->minus = 1;
			else if (format[options->len + 1] == '+')
				options->plus = 1;
			else if (format[options->len + 1] == '0')
			{
				options->zero = 1;
				options->zero_int = 1;
			}
			else if (format[options->len + 1] == ' ')
				write(1, " ", 1);
		}
		options->len = options->len + 1;
	}
}

void		if_widthstar(char *format, t_option *options, va_list args)
{
	if (format[options->len + 1] == '*')
	{
		options->width = va_arg(args, int);
		if (options->width < 0)
		{
			options->minus = 1;
			options->width = -(options->width);
		}
		while (format[options->len + 1] == '*')
			options->len++;
	}
}

void		set_width(char *format, va_list args, t_option *options)
{
	if_widthstar(format, options, args);
	if (format[options->len + 1] >= '0' && format[options->len + 1] <= '9')
	{
		options->width = ft_atoi(&format[options->len + 1]);
		while (ft_isdigit(format[options->len + 1]) == 1)
			options->len++;
		if (format[options->len + 1] == '*')
		{
			if (options->width < 0)
			{
				options->minus = 1;
				options->width = -(options->width);
			}
			while (format[options->len + 1] == '*')
				options->len++;
		}
	}
}

void		if_precsionstar(char *format, t_option *options, va_list args)
{
	int p;

	p = va_arg(args, int);
	if (p >= 0)
		options->precision = p;
	else if (p < 0)
		options->precisiontf = 0;
	while (format[options->len + 1] == '*')
		options->len++;
}

void		set_precision(char *format, va_list args, t_option *options)
{
	if (format[options->len + 1] == '.')
	{
		options->len++;
		if (ft_strchr(CONVERSION, format[options->len + 1]))
			options->precisiontf = -1;
		else if (ft_isdigit(format[options->len + 1]))
		{
			options->precision = ft_atoi(&format[options->len + 1]);
			while (ft_isdigit(format[options->len + 1]))
				options->len++;
		}
		else if (format[options->len + 1] == '*')
			if_precsionstar(format, options, args);
		else if (!(ft_strchr(CONVERSION, format[options->len + 1])))
			options->precisiontf = -1;
	}
}

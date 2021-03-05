/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:48:16 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 14:51:38 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void	set_conversion(char *format, t_option *options, va_list args)
{
	int position;

	position = options->len + 1;
	if (ft_strchr("cspdiuxX%", format[position]))
	{
		if (format[position] == 's')
			ft_string(options, args);
		if (format[position] == 'd' || format[position] == 'i')
			ft_int(options, args);
		if (format[position] == 'X' || format[position] == 'x')
			ft_hexadecimal(format, options, args);
		if (format[position] == '%')
			if_percent(options);
		if (format[position] == 'c')
			ft_char(options, args);
		if (format[position] == 'p')
			ft_pointers(options, args);
		if (format[position] == 'u')
			ifudecint(options, args);
		options->len += 2;
	}
}

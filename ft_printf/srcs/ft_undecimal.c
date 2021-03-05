/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:35:49 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 16:39:18 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

char	*return_decimal_str(uintmax_t n, t_option *options)
{
	char *str;

	str = (char*)malloc(sizeof(char));
	if (n == 0 && options->precision == 0)
		str = "";
	else if (n == 0 && options->precisiontf == -1)
		str = "";
	else if (n == '\0')
		str = "0";
	if (n == '\0' && options->precision == -1)
		str = "";
	else if (n == '\0' && options->precisiontf != -1)
		str = "";
	else
		str = ft_itoa_base(n, 10);
	if (n == 0 && options->precision != 0 && options->precisiontf != -1)
		str = "0";
	if (options->precision != -1)
		str = apply_int_precision(options, str);
	return (str);
}

void	ifudecint(t_option *options, va_list args)
{
	int			c;
	char		*str;
	uintmax_t	n;

	n = (unsigned int)va_arg(args, unsigned int);
	str = return_decimal_str(n, options);
	if (options->zero == 1)
		c = '0';
	else
		c = ' ';
	if (options->minus == 0)
		left_padding_int(str, options, c);
	else
		right_padding_int(str, options, c);
	if (n != '\0')
		free(str);
}

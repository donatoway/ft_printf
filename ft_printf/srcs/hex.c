/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:56:13 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 16:02:52 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

char	*return_hexa_str(char *format, t_option *options, int n)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char*))))
		return (NULL);
	if (n < 0)
		options->sign = NEGATIVE;
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
		str = ft_hex(format, options, n);
	if (n == 0 && options->precision != 0 && options->precisiontf != -1)
		str = "0";
	if (options->precision != -1)
		str = apply_int_precision(options, str);
	return (str);
}

void	ft_hexadecimal(char *format, t_option *options, va_list args)
{
	char			*str;
	unsigned int	n;
	char			c;

	n = va_arg(args, unsigned int);
	if (options->zero == 1)
		c = '0';
	else
		c = ' ';
	str = return_hexa_str(format, options, n);
	if (options->precision != -1)
		str = apply_int_precision(options, str);
	if (options->minus == 0)
		left_padding_int(str, options, c);
	else
		right_padding_int(str, options, c);
	if (n != '\0')
		free(str);
}

char	hexa_convert(char format, int quotient)
{
	char hexa;

	if (quotient < 10)
		hexa = quotient + 48;
	else
	{
		if (format == 'x')
			hexa = quotient + 87;
		if (format == 'X')
			hexa = quotient + 55;
	}
	return (hexa);
}

char	*ft_hex(char *format, t_option *options, unsigned int n)
{
	char	*hexa;
	long	quotient;
	int		i;
	long	tmp;

	i = 0;
	hexa = (char*)malloc(sizeof(char*));
	quotient = n;
	if (quotient == 0)
		hexa = "0";
	while (quotient != 0)
	{
		tmp = quotient % 16;
		hexa[i++] = hexa_convert(format[options->len + 1], tmp);
		quotient /= 16;
	}
	ft_strreverse(hexa);
	return (hexa);
}

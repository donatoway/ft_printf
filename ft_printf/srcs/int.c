/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:03:21 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 16:22:25 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

char	*return_int_str(int n, t_option *options)
{
	char *str;

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
		str = ft_itoa(n);
	if (n == 0 && options->precision != 0 && options->precisiontf != -1)
		str = "0";
	if (options->precision != -1)
		str = apply_int_precision(options, str);
	return (str);
}

void	ft_int(t_option *options, va_list args)
{
	int		c;
	char	*str;
	int		n;

	n = va_arg(args, int);
	if (n < 0)
		options->sign = NEGATIVE;
	str = return_int_str(n, options);
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

char	*if_negative_sign(t_option *options, int j, char *str, int diff)
{
	char	*new_str;
	int		i;

	i = options->i;
	if (!(new_str = (char*)malloc(sizeof(char*))))
		return (NULL);
	if (options->sign == NEGATIVE)
	{
		new_str[i] = '-';
		i++;
		j++;
		diff += 1;
	}
	while (diff--)
		new_str[i++] = '0';
	while (str[j])
	{
		new_str[i] = str[j];
		i++;
		j++;
	}
	options->zero = 0;
	new_str[i] = '\0';
	return (new_str);
}

char	*apply_int_precision(t_option *options, char *str)
{
	int		precision;
	char	*new_str;
	int		i;
	int		diff;
	int		j;

	j = 0;
	i = 0;
	precision = options->precision;
	diff = precision - ft_strlen(str);
	if (!(new_str = (char*)malloc(sizeof(char*))))
		return (NULL);
	if (precision <= ft_strlen(str))
		new_str = str;
	else
	{
		options->i = i;
		new_str = if_negative_sign(options, j, str, diff);
	}
	return (new_str);
}

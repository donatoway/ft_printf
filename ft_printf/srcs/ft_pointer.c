/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:22:50 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 16:31:30 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

char	*apply_point_precision(t_option *option, char *str)
{
	char	*new_str;
	int		diff;
	int		i;
	int		j;

	j = 0;
	i = 0;
	diff = (option->precision) - (ft_strlen(str) - 2);
	new_str = (char*)malloc(sizeof(char));
	if (option->precision <= ft_strlen(str) - 2)
		new_str = str;
	else
	{
		new_str[i++] = '0';
		new_str[i++] = 'x';
		while (diff--)
			new_str[i++] = '0';
		while (str[j])
			new_str[i++] = str[j++ + 2];
		new_str[i] = '\0';
	}
	return (new_str);
}

void	apply_0_width_prec(t_option *option, char *str)
{
	char	*new_str;
	int		diff;
	int		i;
	int		j;

	j = 0;
	i = 0;
	diff = (option->width) - ft_strlen(str);
	new_str = (char*)malloc(sizeof(char));
	if (option->width <= ft_strlen(str))
		new_str = str;
	else
	{
		new_str[i++] = '0';
		new_str[i++] = 'x';
		while (diff--)
			new_str[i++] = '0';
		while (str[j])
			new_str[i++] = str[j++ + 2];
		new_str[i] = '\0';
	}
	ft_putstr(new_str);
	option->nprinted += ft_strlen(new_str);
}

void	apply_rules_point(char *str, t_option *option)
{
	if (option->precision != -1)
		str = apply_point_precision(option, str);
	if (option->zero != 0 && option->precision == -1)
	{
		if (option->minus != 0)
			right_padding_int(str, option, ' ');
		else
			apply_0_width_prec(option, str);
	}
	else
	{
		if (option->minus == 0)
			left_padding_int(str, option, ' ');
		else
			right_padding_int(str, option, ' ');
	}
}

void	ft_pointers(t_option *option, va_list args)
{
	char	*str;

	str = conv_p(option, args);
	apply_rules_point(str, option);
	free(str);
}

char	*conv_p(t_option *options, va_list ap)
{
	void	*str;
	char	*res;
	char	*conv;

	str = va_arg(ap, void *);
	if (!(res = ft_strnew(19)))
		exit_error("error: malloc failed\n", 1, str);
	ft_strncpy(res, "0x", 2);
	conv = ft_itoa_base((unsigned long int)str, 16);
	ft_strncat(res, conv, 16);
	free(conv);
	if (str == NULL && (options->precisiontf == -1 || options->precision == 0))
		res[2] = '\0';
	return (res);
}

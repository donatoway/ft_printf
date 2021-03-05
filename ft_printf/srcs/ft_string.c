/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:02:09 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 15:49:01 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void	ft_string(t_option *options, va_list args)
{
	int		c;
	char	*str;

	str = va_arg(args, char *);
	if (options->zero == 1)
		c = '0';
	else
		c = ' ';
	if (str == NULL && options->precisiontf == 0)
		str = "(null)";
	else if (options->precisiontf == -1)
		str = "";
	if (options->precision != -1)
		str = apply_precision_string(str, options);
	if (options->minus == 0)
		left_padding(str, options, c);
	else if (options->minus != 0)
		right_padding(str, options, c);
}

void	left_padding(char *str, t_option *options, int c)
{
	if (options->width <= ft_strlen(str))
	{
		ft_putstr(str);
		options->nprinted += ft_strlen(str);
	}
	else
	{
		if (options->width > ft_strlen(str))
		{
			while (options->width > ft_strlen(str))
			{
				write(1, &c, 1);
				options->nprinted++;
				options->width--;
			}
			ft_putstr(str);
			options->nprinted += ft_strlen(str);
		}
	}
}

void	right_padding(char *str, t_option *options, int c)
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

char	*apply_precision_string(char *str, t_option *options)
{
	int		precision;
	char	*new_str;
	int		i;

	i = 0;
	precision = options->precision;
	if (!(new_str = malloc(sizeof(char) * (precision + 1))))
		return (NULL);
	if (precision >= ft_strlen(str))
		new_str = str;
	else
	{
		while (precision--)
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}

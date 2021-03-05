/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:08:56 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 15:12:40 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void	setzero_all(t_option *option)
{
	option->nprinted = 0;
	option->len = 0;
	option->minus = 0;
	option->plus = 0;
	option->space = 0;
	option->zero = 0;
	option->hash = 0;
	option->width = 0;
	option->precisiontf = 0;
	option->precision = -1;
	option->length = 0;
	option->sign = 0;
	option->zero_int = 0;
}

void	setzero(t_option *option)
{
	option->minus = 0;
	option->plus = 0;
	option->space = 0;
	option->zero = 0;
	option->hash = 0;
	option->width = 0;
	option->precisiontf = 0;
	option->precision = -1;
	option->length = 0;
	option->sign = 0;
	option->zero_int = 0;
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

int		ft_atoi(const char *str)
{
	int		res;
	int		negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
		*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

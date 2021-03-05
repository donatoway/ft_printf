/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:39:43 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 16:47:28 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

char	*ft_itoa_base(uintmax_t value, uintmax_t base)
{
	char					*s;
	unsigned long long		n;
	int						i;

	i = 1;
	n = value;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i-- > 0)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (s);
}

int		unsigned_nbr_len(uintmax_t n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	findchar(t_option *option)
{
	char c;

	if (option->zero)
		c = '0';
	else
		c = ' ';
	return (c);
}

void	lengths(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

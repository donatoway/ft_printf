/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:12:56 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/13 15:55:11 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		len(long nb)
{
	int len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void	ft_strreverse(char *s)
{
	long	i;
	char	tmp;

	if (s)
	{
		i = -1;
		while (++i < (ft_strlen(s) / 2))
		{
			tmp = *(s + i);
			*(s + i) = *(s + ft_strlen(s) - 1 - i);
			*(s + ft_strlen(s) - 1 - i) = tmp;
		}
	}
}

void	ft_bzero(void *s, size_t len)
{
	unsigned long	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	if (len <= 0)
		return ;
	while (i < len)
	{
		ptr[i++] = '\0';
	}
}

char	*ft_itoa(int n)
{
	size_t		len;
	int			weight;
	size_t		cur;
	char		*str;

	lengths(n, &len, &weight);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	cur = 0;
	if (n < 0)
	{
		str[cur] = '-';
		cur++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		str[cur++] = -(n / weight % 10) + 48;
		weight /= 10;
	}
	str[cur] = '\0';
	return (str);
}

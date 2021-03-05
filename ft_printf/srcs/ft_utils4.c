/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 17:02:21 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/14 17:07:16 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_lib.h"

void	exit_error(char *er_mess, int nbfree, ...)
{
	va_list	ap;

	write(1, er_mess, ft_strlen(er_mess));
	va_start(ap, nbfree);
	while (nbfree--)
		free(va_arg(ap, void *));
	va_end(ap);
	exit(0);
}

char	*ft_strnew(size_t size)
{
	char	*res;

	if (!(res = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(res, sizeof(char) * (size + 1));
	return (res);
}

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (i < n && s2[i])
	{
		s1[j + i] = s2[i];
		i++;
	}
	s1[j + i] = '\0';
	return (s1);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (dst);
	else
	{
		while (src[i] && i < len)
		{
			dst[i] = src[i];
			i++;
		}
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

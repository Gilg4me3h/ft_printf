/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muballou <muballou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 01:39:01 by muballou          #+#    #+#             */
/*   Updated: 2026/11/14 21:35:36 by muballou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pchar(char c)
{
	return (write(1, &c, 1));
}

int	pstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		pchar(s[i]);
		i++;
	}
	return (i);
}

int	pnum(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += pchar('-');
		n *= -1;
	}
	if (n > 9)
		count += pnum(n / 10);
	count += pchar((n % 10) + '0');
	return (count);
}

int	punum(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += punum(n / 10);
	count += pchar((n % 10) + '0');
	return (count);
}

int	phexa(unsigned long long n, char c)
{
	char	*arr;
	int		count;

	if (c == 'x')
		arr = "0123456789abcdef";
	else
		arr = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += phexa(n / 16, c);
	count += pchar(arr[n % 16]);
	return (count);
}

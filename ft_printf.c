/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muballou <muballou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 01:21:01 by muballou          #+#    #+#             */
/*   Updated: 2026/11/15 11:55:59 by muballou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pmem(void *n)
{
	unsigned long long	nb;
	int					count;

	if (n == NULL)
		return (write(1, "(nil)", 5));
	nb = (unsigned long long)n;
	count = 0;
	count += write(1, "0x", 2);
	count += phexa(nb, 'x');
	return (count);
}

int	ft_check(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count += pchar('%');
	if (c == 'c')
		count += pchar(va_arg(ap, int));
	if (c == 's')
		count += pstr(va_arg(ap, char *));
	if (c == 'd' || c == 'i')
		count += pnum(va_arg(ap, int));
	if (c == 'u')
		count += punum(va_arg(ap, unsigned int));
	if (c == 'x' || c == 'X')
		count += phexa(va_arg(ap, unsigned long long), c);
	if (c == 'p')
		count += pmem(va_arg(ap, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
				count += ft_check(ap, format[++i]);
		}
		else
			count += pchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

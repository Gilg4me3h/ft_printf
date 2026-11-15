/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muballou <muballou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 01:20:45 by muballou          #+#    #+#             */
/*   Updated: 2026/11/14 21:37:39 by muballou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		pchar(char c);
int		pstr(char *s);
int		pnum(int n);
int		punum(unsigned int n);
int		phexa(unsigned long long n, char c);
int		pmem(void *n);
int		ft_printf(const char *format, ...);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:49:49 by nmagdano          #+#    #+#             */
/*   Updated: 2024/03/02 13:57:39 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*print_format(int *i, const char *format, va_list mood)
{
	format++;
	if (*format == 'c')
		*i += ft_putcharlen((char)va_arg(mood, int));
	else if (*format == 's')
		*i += ft_putstrlen(va_arg(mood, char *));
	else if (*format == 'p')
		*i += ft_print_p(va_arg(mood, unsigned long long));
	else if (*format == 'd' || *format == 'i')
		*i += ft_print_d(va_arg(mood, int));
	else if (*format == 'u')
		*i += ft_print_u(va_arg(mood, unsigned int));
	else if (*format == 'x')
		*i += thex(va_arg(mood, unsigned int), 0);
	else if (*format == 'X')
		*i += thex(va_arg(mood, unsigned int), 1);
	else if (*format == '%')
		*i += write(1, "%", 1);
	else
		*i += write(1, &format[0], 1);
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	mood;
	int		i;

	i = 0;
	va_start(mood, format);
	while (*format != '\0')
	{
		if (*format == '%')
			format = print_format(&i, format, mood);
		else if (*format != '\0')
		{
			ft_putcharlen(*format);
			i++;
		}
		format++;
	}
	va_end(mood);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:46:43 by aantonie          #+#    #+#             */
/*   Updated: 2024/04/03 18:32:30 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(va_list args, const char *format)
{
	int	length;

	length = 0;
	if (*format == 'c')
		length += ft_print_char(va_arg(args, int));
	else if (*format == 'd' || *format == 'i')
		length += ft_print_nbr(va_arg(args, int));
	else if (*format == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (*format == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (*format == 'x' || *format == 'X')
		length += ft_print_hex(va_arg(args, unsigned int), *format);
	else if (*format == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*format == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *form_str, ...)
{
	va_list	ap;
	int		i;
	int		format_len;

	va_start(ap, form_str);
	i = 0;
	format_len = 0;
	while (*form_str != '\0')
	{
		if (*form_str == '%')
		{
			format_len = ft_formats(ap, ++form_str);
			i = i + format_len;
		}
		else
		{
			format_len = ft_print_char(*form_str);
			i++;
		}
		form_str++;
	}
	va_end(ap);
	return (i);
}

// #include <stdio.h>

// int main(void)
// {
// 	ft_printf("OurPrint:%s\n", "");
// 	printf("NormalPrint:%s", "");
// 	return (0);
// }

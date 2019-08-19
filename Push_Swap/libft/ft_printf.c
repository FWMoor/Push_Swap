/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:23:22 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/18 16:11:16 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	return (ft_format_all(format, args, 1));
}

int				ft_fdprintf(int fd, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	return (ft_format_all(format, args, fd));
}

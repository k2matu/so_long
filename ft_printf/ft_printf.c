/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:59:38 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/05 15:23:17 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	match(const char *str, va_list args, int len, int i)
{
	int	j;

	j = 0;
	while (j < 9)
	{
		if (str[i + 1] == CONVERSION[j])
		{
			j = g_printf[j](args, CONVERSION[j]);
			if (j == -1)
				return (-1);
			len += j;
			break ;
		}
		j++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			len;
	va_list		args;

	va_start(args, str);
	i = -1;
	len = 0;
	while (str[++i])
	{
		while (str[i] == '%')
		{
			len = match(str, args, len, i);
			if (len == -1)
				return (-1);
			if (!str[i + 2])
				return (len);
			i += 2;
		}
		if (write(1, &str[i], 1) == -1)
			return (-1);
		len++;
	}
	va_end(args);
	return (len);
}

// int main() {

// 	// long long i = LONG_MIN;
// 	int j;
// 	int k;

// 	k = 0;
// 	k = ft_printf("%p", (void *)-14523);
// 	printf("\n");
//     j = printf("%p", (void *)-14523);
// 	printf("\n");

// 	printf("%d / %d", k, j);
//     return 0;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 08:19:45 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/05 15:23:51 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned char	a;
	int				i;

	a = c;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != a)
		i++;
	if (str[i] == a)
	{
		i++;
		return (&str[i]);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (!s2 && !s1)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (j + 1));
	if (!dest)
	{
		free(s1);
		return (NULL);
	}
	dest[j] = '\0';
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		dest[i++] = s2[j++];
	free(s1);
	return (dest);
}

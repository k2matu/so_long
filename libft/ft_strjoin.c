/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:21:59 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/05 15:25:40 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (*s1)
		dest[i++] = *s1++;
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:06:46 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/05 15:26:03 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = ft_strlen(s);
	if (start >= j)
		len = 0;
	if (len > (j - start))
		len = j - start;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest || !s)
		return (NULL);
	while (i < len && s[i])
	{
		dest[i] = s[(start + i)];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 07:55:51 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/14 12:56:34 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_arr(char **value)
{
	int	i;

	i = 0;
	if (value == NULL)
		return ;
	while (value[i])
		free(value[i++]);
	free(value);
}

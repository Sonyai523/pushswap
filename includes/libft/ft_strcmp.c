/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:22:44 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 16:22:46 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s_1, const char *s_2)
{
	int	i;

	i = 0;
	while (s_1[i] != '\0' || s_2[i] != '\0')
	{
		if (s_1[i] != s_2[i])
			return ((unsigned char)s_1[i] - (unsigned char)s_2[i]);
		i++;
	}
	return (0);
}

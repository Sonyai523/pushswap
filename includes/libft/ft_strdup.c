/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:23:05 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 16:23:19 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		i;

	i = 0;
	a = (char *)malloc(sizeof(*s1) * ft_strlen(s1) + 1);
	if (!a)
		return (NULL);
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

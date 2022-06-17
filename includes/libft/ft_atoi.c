/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:20:59 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 16:21:09 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		dig;
	long	rezult;

	sign = 1;
	dig = 0;
	rezult = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == ' ' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		rezult = rezult * 10 + (*str - '0');
		dig++;
		if (dig > 10 || (rezult * sign) > MAXINT || (rezult * sign) < MININT)
			ft_error();
		str++;
	}
	return ((int)(rezult * sign));
}

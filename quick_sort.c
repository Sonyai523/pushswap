/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:14:59 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 16:15:00 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	ft_quick_sort - Запуск быстрой сортировки массива чисел, рекурсивно.
void	ft_quick_sort(int *array, int start, int end)
{
	int	q;

	if (start < end)
	{
		q = ft_partition(array, start, end);
		ft_quick_sort(array, start, q - 1);
		ft_quick_sort(array, q + 1, end);
	}
}

//	ft_partition - Разбиение массива и основной процесс сортировки.
int	ft_partition(int *array, int start, int end)
{
	int	piv;
	int	i;
	int	temp;
	int	j;

	piv = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= piv)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return (i + 1);
}

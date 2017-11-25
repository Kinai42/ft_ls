/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_uns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:27:21 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 21:16:11 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void		ft_itoabase_uns(unsigned long long int nb, int b, char c, char *str)
{
	int comma;

	comma = 0;
	while (nb >= (unsigned long long)b)
	{
		if (comma++ && comma % 4 == 0 && c > 0 && b == 10)
			*(str--) = ',';
		else
		{
			*(str--) = c < 'a' ? BASE_MAJ(nb % b) : BASE_MIN(nb % b);
			nb /= b;
		}
	}
	if (comma++ && comma % 4 == 0 && c > 0 && b == 10)
		*(str--) = ',';
	*(str--) = c < 'a' ? BASE_MAJ(nb % b) : BASE_MIN(nb % b);
}

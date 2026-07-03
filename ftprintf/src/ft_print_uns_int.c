/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:27:06 by gustde-s          #+#    #+#             */
/*   Updated: 2026/07/03 16:48:25 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uns_int(unsigned int n)
{
	int	count;
	int	digit;

	count = 0;
	if (n >= 10)
		count += ft_print_uns_int(n / 10); // faz a recursão para isolar os valores à direita -> se for >= 10
	digit = (n % 10) + '0'; // faz a conversão do digito para char e armazena na var
	write(1, &digit, 1); // imprime o valor armazenado em digit
	return (count + 1); // cada vez que a recursão acontece, o count recebe mais 1
}

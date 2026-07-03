/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:26:49 by gustde-s          #+#    #+#             */
/*   Updated: 2026/07/03 17:18:18 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format)
{
	char	*base;
	char	digit;
	int		count;

	if (format == 'x') // checamos se o format é x ou X
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF"; // a escolha do hex ser maiusculo ou minusculo é puramente por estetica e/ou preferencia, matematicamente n muda nd
	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16, format);
	digit = base[n % 16];
	write(1, &digit, 1);
	return (count + 1);
}

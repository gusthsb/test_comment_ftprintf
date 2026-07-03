/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:27:03 by gustde-s          #+#    #+#             */
/*   Updated: 2026/07/03 16:28:13 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *s)
{
	int	i;

	if (!s) // security-guard, checando se a string está vazia
	{
		write(1, "(null)", 6); // imprime (null), saida padrão se a str for nula no printf padrão
		return (6); // retorna qnt de char impressos no write acima
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1); // imprime cada indice da str
		i++; // passa pela str, char por char
	}
	return (i); // retorna valor total da str impressa
}

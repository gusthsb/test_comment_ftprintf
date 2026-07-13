/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:26:54 by gustde-s          #+#    #+#             */
/*   Updated: 2026/07/13 17:10:17 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int	count;
	int	digit;

	count = 0;
	if (n == -2147483648) // checar se for o menor numero de um int
	{
		write(1, "-2147483648", 11); // imprime ele na tela
		return (11); // retorna qnt de char da str
	}
	if (n < 0)
	{
		write(1, "-", 1); // imprime o sinal de negativo
		count++; // +1 no count por conta da impressao do -
		n = -n; // transformamos o int negativo para positivo || -(-42) n * -n vira n posiivo
	}
	if (n >= 10)	
		count += ft_print_int(n / 10); // faz a recursão para isolar o valor mais à direta e "pausa" a chamada atual -- o valor modificado so fica na chamada func
	digit = (n % 10) + '0'; // faz a conversão do n atual -> e armazena na variavel 
	write(1, &digit, 1); // imprime o char ja convertido armazenado em digit
	return (count + 1); // retorno do count + o ultimo digito impresso
}

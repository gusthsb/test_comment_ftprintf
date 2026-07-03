/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:26:59 by gustde-s          #+#    #+#             */
/*   Updated: 2026/07/03 17:28:03 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_pointer(unsigned long n) // unsigned long, pois tem uma capacidade de armazenamento bem maior que
{									           // o unsigned int, ideal para quando vamos trabalhar com ponteiros, endereços de memoria
	char	*base;
	char	digit;
	int		count;

	base = "0123456789abcdef"; // base como auxiliar tendo uma str para fazermos a conversão do long
	count = 0;
	if (n >= 16)
		count += print_hex_pointer(n / 16); // usamos a mesma base de recursão do int/uns_int, isolar o item mais à direita e "pausar".
	digit = base[n % 16];
	write(1, &digit, 1);
	return (count + 1);
}
// o count(n/16) pega o primeiro indice da base, exemplo, puxando a função com o n = 78, ele vai ver quantas vezes o 16 consegue
// dividir o n e setar essa quantidade como o primeiro indice que vamos escrever, no caso --- 4
// depois, ele vai pegar o resto com o digit, o resto de 78 % 16 é 14 e 14 baseado na base hexadecimal que criamos é igual à e
// pegando o resultado de digit conseguimos imprimir então 4e, que é a conversão para hexadecimal do long
int	ft_print_pointer(void *ptr)
{
	if (!ptr) // security-guard para o ptr, checa se ele está vazio
	{
		write(1, "(nil)", 5); // (nil) saida de "erro" padrão do printf original
		return (5); // qnt de char em (nil)
	}
	write(1, "0x", 2); // todo ponteiro precisa começar com 0x
	return (print_hex_pointer((unsigned long)ptr) + 2); // no return, chamamos a func aux que criamos e passamos o ptr como parametro
}														// e somamos + 2 para completar a qnt de char que vamos imprimir (+ 2 por conta do 0x)

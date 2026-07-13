/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:25:56 by gustde-s          #+#    #+#             */
/*   Updated: 2026/07/13 19:01:48 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_handle(char format, va_list args) // format para receber o char depois de % e args para receber uma lista
{													 // de argumentos variadicos - e extrair os valores com va_arg
	if (format == 'c')                             // mesmo com a função recebendo um char como parametro, o proprio C faz uma 
		return (ft_print_char(va_arg(args, int))); // "conversão" de tipo para int
	else if (format == 's')
		return (ft_print_string(va_arg(args, char *))); 
	else if (format == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (format == 'd')
		return (ft_print_int(va_arg(args, int)));
	else if (format == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_uns_int(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_print_char('%'));
	else if (format == 'a') // re-coding not in project
		return (ft_print_42());
	return (0);
	/* usamos if e else if para verificar qual sera a flag utilizada e consequentemente a função que vai ser chamada*/
}

int	ft_printf(const char *format, ...) // recebe uma string imutavel e uma quantidade variável de argumentos
{
	va_list	args; // guarda lista de argumentos
	int		count; // contador de char impressos
	int		i; // indice (contador) para percorrer format

	va_start(args, format); // inicializa args, resumidamente -- para ler os args após o format
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%') // verificar se o i é %, se for, chama a função auxiliar.
		{
			count += format_handle(format[i + 1], args); // count recebe o resultado da função (que todas as funções retornam basicamente o size da impressão)
			i++;                                         // e chama a format com o parametro seguinte de %  -- no caso o i + 1 e passa tambem os args
		}
		else
			count += ft_print_char(format[i]); // se a o if acima não acontecer, count recebe o valor da função chamada e printamos somente o %
		i++;
	}
	va_end(args); // encerramos o va_start e o uso dos argumentos variadicos
	return (count); // retornamos o total de count  -- total de char impressos
}

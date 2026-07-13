/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:13:55 by gustde-s          #+#    #+#             */
/*   Updated: 2026/07/13 19:01:31 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_string(char *s);
int	ft_print_int(int n);
int	ft_print_uns_int(unsigned int n);
int	ft_print_hex(unsigned int n, char format);
int	ft_print_pointer(void *ptr);
int	ft_print_42(void); // re-coding not in project

#endif
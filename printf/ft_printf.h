/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:02:00 by ntome             #+#    #+#             */
/*   Updated: 2025/10/21 14:25:55 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_print_flag(const char c, va_list params);
int		ft_write_char(char c);
int		ft_write_str(char *str);
int		ft_put_nbr(int nb);
int		ft_write_hexa(unsigned int nb, int upper);
int		ft_write_ptr(void *ptr);
int		ft_write_unsigned(unsigned int nb);
int		ft_strlen(char *str);
int		ft_get_int_size(int n);
int		ft_get_ptr_size(void *ptr);
int		ft_get_unsigned_size(unsigned int n);
int		ft_get_hexa_size(unsigned int n);
int		ft_get_ptr_in_hexa_size(uintptr_t nb);
void	ft_write_ptr_in_hexa(uintptr_t nb);
#endif

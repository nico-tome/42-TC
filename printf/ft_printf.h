/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:02:00 by ntome             #+#    #+#             */
/*   Updated: 2025/10/21 12:16:51 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
void	ft_print_flag(const char c, va_list params);
int		ft_get_flag_size(const char c, va_list params);
void	ft_write_char(const char c);
void	ft_write_str(const char *str);
void	ft_put_nbr(int nb);
void	ft_write_hexa(unsigned int nb, int upper);
void	ft_write_ptr(void *ptr);
void	ft_write_unsigned(unsigned int nb);
int		ft_strlen(const char *str);
int		ft_get_int_size(int n);
int		ft_get_ptr_size(void *ptr);
int		ft_get_unsigned_size(unsigned int n);
int		ft_get_hexa_size(unsigned int n);
#endif

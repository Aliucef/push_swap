/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:11:59 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/26 09:24:13 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// % [flags] [width] [.precision] [specifier]

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include "../../libft/libft.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		has_precision;
	int		plus;
	int		space;
	int		hash;
	char	specifier;
}	t_flags;

int		ft_print_int(int n, t_flags f);
int		ft_print_unsigned(unsigned int n, t_flags f);
int		ft_printf(const char *format, ...);
int		parse_flags(const char *fmt, int i, t_flags *f);
int		ft_numlen(int n);
int		ft_unsigned_numlen(unsigned int n);
int		ft_putnchar(char c, int n);
void	ft_putnbr_base(unsigned int nbr, char *base);
void	ft_unsigned_putnbr(unsigned int n);
void	ft_putnbr_long(long n);
int		ft_print_char(int n, t_flags f);
void	ft_get_params(int len, t_flags f, int *arr);
int		ft_print_str(char *str, t_flags f);
int		ft_print_hex(unsigned int n, int is_cap, t_flags f);
int		ft_put_unsigned_prefix(t_flags f, int spaces);
int		ft_unsigned_len(unsigned int n, t_flags f);
int		get_nbr_len_in_hex(unsigned int n);
int		ft_print_pointer(void *str, t_flags f);
void	ft_putnbr_base_long(unsigned long long nbr, char *base);

#endif

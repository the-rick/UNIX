/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:20:08 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:44:43 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "aux.h"

# define FAIL				-1
# define SPECIFIER			"sSpdDioOuUxXcCb"

typedef struct				s_printf
{
	int flags;
	int width;
	int precision;
}							t_printf;

# define LOW_S				0
# define UPPER_S			1
# define LOW_P				2
# define LOW_D				3
# define UPPER_D			4
# define LOW_I				5
# define LOW_O				6
# define UPPER_O			7
# define LOW_U				8
# define UPPER_U			9
# define LOW_X				10
# define UPPER_X			11
# define LOW_C				12
# define UPPER_C			13
# define LOW_B				14

# define HASH				(1 << (0))
# define ZERO				(1 << (1))
# define MINUS				(1 << (2))
# define PLUS				(1 << (3))
# define SPACE				(1 << (4))
# define HH					(1 << (5))
# define H					(1 << (6))
# define LL					(1 << (7))
# define L					(1 << (8))
# define J					(1 << (9))
# define Z					(1 << (10))
# define WIDTH				(1 << (11))
# define PRECISION			(1 << (12))

# define LOW_S_BIT			(1 << (13))
# define UPP_S_BIT			(1 << (14))
# define LOW_P_BIT			(1 << (15))
# define LOW_D_BIT			(1 << (16))
# define UPP_D_BIT			(1 << (17))
# define LOW_I_BIT			(1 << (18))
# define LOW_O_BIT			(1 << (19))
# define UPP_O_BIT			(1 << (20))
# define LOW_U_BIT			(1 << (21))
# define UPP_U_BIT			(1 << (22))
# define LOW_X_BIT			(1 << (23))
# define UPP_X_BIT			(1 << (24))
# define LOW_C_BIT			(1 << (25))
# define UPP_C_BIT			(1 << (26))
# define LOW_B_BIT			(1 << (27))

int							ft_printf(const char *format, ...);

int							parse_attributes(char **format, va_list arg, \
		t_printf *ptr);
int							return_specifier(va_list arg, char **format, \
		t_printf *ptr);
int							handle_wide_strings(va_list arg, t_printf *ptr);
int							handle_wide_chars(va_list arg, t_printf *ptr);
int							handle_strings(va_list arg, t_printf *ptr);
int							handle_characters(va_list arg, t_printf *ptr);
int							handle_decimal(va_list arg, t_printf *ptr);
int							handle_binary(va_list arg, t_printf *ptr);
int							handle_hexadecimal(va_list arg, t_printf *ptr);
int							handle_octal(va_list arg, t_printf *ptr);
int							get_num_spaces(int width, int len, int attr);

int							ft_decimal_type(uintmax_t num, int attr, int prec);
int							ft_unsigned_format(uintmax_t num, t_printf *ptr, \
		char *(*convert)(uintmax_t, int*));
int							ft_signed_format(intmax_t num, t_printf *ptr);
int							ft_get_spaces(int attr, int size, int *len);
int							ft_get_zeroes(t_printf *ptr, int *len, int sign);
int							get_spaces(int width, int len, int attr);
char						*ft_convert_number(uintmax_t num, int *digits, \
		int base);
char						*ft_convert_bin(uintmax_t num, int *size);
char						*ft_convert_octal(uintmax_t num, int *size);
int							ft_signed_number(va_list arg, t_printf *ptr);
int							ft_unsigned_number(va_list arg, t_printf *ptr);
char						*octal(uintmax_t num, int *size);
char						*binary(uintmax_t num, int *size);
char						*ft_get_hex(uintmax_t num, char *hex, char *str);
int							ft_hex_digits(uintmax_t num);
char						*hex(uintmax_t num, int *num_digits);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yprint_format.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:56:46 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 12:56:47 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YPRINT_FORMAT_H
# define YPRINT_FORMAT_H
# include <stdarg.h>
# include <ctype.h>
# include "ytypes.h"

// Represents conversion type
typedef enum e_pconvtype {
	UNKNOWN,
	CHAR,
	STRING,
	HEXPTR,
	DECIMAL,
	INTEGER,
	UDECIMAL,
	HEX,
	UHEX,
	PERCENT,
	FORMAT_TYPE_COUNT,
}	t_pconvtype;

// Printing conversion data
typedef struct s_pconvdata {
	t_pconvtype		type;
	t_bool			alt_form;
	t_bool			left_adjust;
	t_bool			sign_flag;
	t_bool			space_flag;
	t_bool			zero_padding;
	t_bool			precision_flag;
	unsigned int	precision;
	unsigned int	field_width;
}	t_pconvdata;

t_pconvdata	make_convdata(void);
const char	*configure_convdata(t_pconvdata *data, const char *str);
t_pconvtype	get_convtype(const char c);
t_pconvdata	parse_format_conversion(const char **str);
t_pconvdata	parse_iformat_conversion(const char *str, t_uint *i);

char		*format_none(va_list *args, t_pconvdata cdata);
char		*format_unknown(va_list *args, t_pconvdata cdata);
char		*format_char(va_list *args, t_pconvdata cdata);
char		*format_string(va_list *args, t_pconvdata cdata);
char		*format_ptr(va_list *args, t_pconvdata cdata);
char		*format_decimal(va_list *args, t_pconvdata cdata);
char		*format_int(va_list *args, t_pconvdata cdata);
char		*format_unsigned_decimal(va_list *args, t_pconvdata cdata);
char		*format_hex(va_list *args, t_pconvdata cdata);
char		*format_uhex(va_list *args, t_pconvdata cdata);
char		*format_percent(va_list *args, t_pconvdata cdata);

char		*ptr_hexstring(t_uint_ptr v, t_bool uppercase);
char		*uint_hexstring(unsigned int v, t_bool uppercase);
char		*utoa(unsigned int n);
char		*number_padding(char *str, int i, char s, t_pconvdata c);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycstr_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:52:01 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/21 12:53:55 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ycstr.h"
#include "ydefines.h"
#include "ymath.h"
#include <stdlib.h>

char	*cstr_itoa(int n)
{
	int		i;
	char	*str;
	int		temp;

	if (n == -2147483648)
		return (cstr_dup("-2147483648"));
	temp = int_abs(n);
	i = n < 0;
	while (++i && temp >= 10)
		temp = temp / 10;
	temp = int_abs(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (YNULL);
	str[i] = '\0';
	while (--i >= 0 && temp >= 10)
	{
		str[i] = (temp % 10) + '0';
		temp /= 10;
	}
	str[i] = (temp % 10) + '0';
	str[0] = (n < 0) * '-' + (n >= 0) * (temp + '0');
	return (str);
}

int	cstr_atoi(const char *str)
{
	int	result;
	int	sign;

	if (!str)
		return (0);
	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10;
		result += (int) *str - '0';
		str++;
	}
	return (result * sign);
}

static int	char_in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*cstr_trim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	c;

	if (!s1)
		return (YNULL);
	if (!set)
		return (cstr_dup(s1));
	if (cstr_len(s1) == 0)
		return (cstr_sub(s1, 0, 0));
	i = 0;
	while (char_in_set(s1[i], set))
		i++;
	c = i;
	i = cstr_len(s1) - 1;
	while (char_in_set(s1[i], set) && i > c)
		i--;
	return (cstr_sub(s1, c, i - c + 1));
}

char	*cstr_sub(char const *s, unsigned int st, unsigned int len)
{
	char			*result;
	unsigned int	i;

	if (!s)
		return (YNULL);
	i = cstr_len(s);
	if (st > i)
		st = i;
	if (len + st > i)
		len = i - st;
	result = (char *)malloc(sizeof (char) * len + 1);
	if (!result)
		return (YNULL);
	i = 0;
	while (s[st + i] != '\0' && i < len)
	{
		result[i] = s[st + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

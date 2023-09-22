/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yio_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:57:41 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/04/04 13:57:42 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yio.h"
#include "ylist.h"
#include <fcntl.h>
#include "ydefines.h"
#include <sys/errno.h>
#include <stdlib.h>
#include "ycstr.h"
#include "ystring.h"

t_bool	try_open_file(const t_string *str, int flags, int *fd)
{
	return (try_open_file_cstr(str->cstr, flags, fd));
}

t_bool	try_open_file_cstr(const char *cstr, int flags, int *fd)
{
	int			open_result;
	extern int	errno;

	open_result = open(cstr, flags, 0644);
	if (open_result < 0)
	{
		*fd = errno;
		return (FALSE);
	}
	*fd = open_result;
	return (TRUE);
}

t_list	*read_fd_to_lines(int fd)
{
	t_list		*lines;
	char		*line;
	t_string	*str;

	lines = list_new();
	line = get_next_line(fd);
	while (line)
	{
		str = string_from_cstr(line);
		list_insert(lines, string_trim_cstr(str, "\n"));
		string_delete(str);
		free(line);
		line = get_next_line(fd);
	}
	return (lines);
}

t_list	*read_file_to_lines(const t_string *str, int flags)
{
	int	fd;

	if (try_open_file(str, flags, &fd))
	{
		return (read_fd_to_lines(fd));
	}
	return (YNULL);
}

t_list	*read_file_to_lines_cstr(const char *str, int flags)
{
	int	fd;

	if (try_open_file_cstr(str, flags, &fd))
	{
		return (read_fd_to_lines(fd));
	}
	return (YNULL);
}

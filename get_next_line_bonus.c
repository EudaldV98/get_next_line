/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:10:16 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/05 15:47:09 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void			*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)b;
	while (len > 0)
	{
		*(ptr++) = (unsigned char)c;
		len--;
	}
	return (b);
}

void			*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(ptr = (unsigned char *)malloc(sizeof(size) * count)))
		return (NULL);
	ft_memset(ptr, 0, count);
	return ((void *)ptr);
}

int				ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
	return (0);
}

static char		*new_str(char *string)
{
	if (ft_strchr(string, '\n'))
	{
		ft_strcpy(string, ft_strchr(string, '\n') + 1);
		return (string);
	}
	else if (ft_strlen(string) > 0)
	{
		ft_strcpy(string, ft_strchr(string, '\0'));
		return (string);
	}
	return (NULL);
}

int				get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*st[MAX];
	int				r;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(st[fd]) && !(st[fd] = ft_calloc(1, sizeof(int))))
		return (-1);
	while (!(ft_strchr(st[fd], '\n')) && (r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp = st[fd];
		st[fd] = ft_strjoin(tmp, buff, r);
		free(tmp);
	}
	tmp = ft_substr(st[fd], 0, ft_strlen(st[fd]));
	*line = tmp;
	tmp = NULL;
	free(tmp);
	tmp = NULL;
	if (ft_strchr(st[fd], '\n') == NULL)
		return (ft_strdel(&st[fd]));
	return ((new_str(st[fd]) == NULL) ? 0 : 1);
}

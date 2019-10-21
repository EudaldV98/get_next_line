/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:10:16 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/21 16:16:50 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char		*new_str(char *string)
{
	if (ft_strchr(string, '\n'))
	{
	 	ft_strcpy(string, ft_strchr(string, '\n') + 1);
		return (string);
	}
	if (ft_strlen(string) > 0)
	{
		ft_strcpy(string, ft_strchr(string, '\0'));
		return (string);
	}
	return (NULL);
}

int				get_next_line(int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*st[2147483647];
	int				res;
	char			*tmp;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (!(st[fd]) && (st[fd] = malloc(sizeof(char) * 1)) == NULL)
		return (-1);
	while (!(ft_strchr(st[fd], '\n')) && (res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		tmp = st[fd];
		st[fd] = ft_strjoin(tmp, buff, res);
		free(tmp);
	}
	*line = ft_substr(st[fd], 0, ft_strlen(st[fd]));
	if (new_str(st[fd]) == NULL)
		return (0);
	return (1);
}

// int     main(void)
// {
//     int     fd;
//     int     ret;
//     char    *line;

//     if ((fd = open("t2.txt", O_RDONLY)) < 3 && fd != 0)
//         return (-1);
//     printf("%d\n", fd);
//     ret = get_next_line(fd, &line);
//     printf("%d - %s\n", ret, line);
//     ret = get_next_line(fd, &line);
//     printf("%d - %s\n", ret, line);
//     ret = get_next_line(fd, &line);
//     printf("%d - %s\n", ret, line);
//     ret = get_next_line(fd, &line);
//     printf("%d - %s\n", ret, line);
//     return (0);
// }
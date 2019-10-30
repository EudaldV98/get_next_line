/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_multiple_files.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:44:34 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/21 17:13:58 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char const *argv[]) {
	int fd;
	int fd_2;
	int i;
	char *line;
	int status;

	fd = open(argv[1], O_RDONLY);
	fd_2 = open(argv[2], O_RDONLY);
	i = 1;
	while (((status = get_next_line(fd, &line)) == 1) || ((status = get_next_line(fd_2, &line)) == 1))
	{
		printf("[%d] %s\n", i++, line);
		free(line);
	}
	close(fd);
	close(fd_2);
	return (argc);
}
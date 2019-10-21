/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:07:52 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/18 12:23:53 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

# define BUFF_SIZE 32

int		        get_next_line(int fd, char **line);
size_t	        ft_strlen(const char *str);
char            *ft_strcpy(char *dest, const char *src);
char	        *ft_strjoin(char *s1, char *s2, size_t len);
char	        *ft_substr(char const *s, unsigned int start, size_t len);
char	        *ft_strchr(const char *s, int c);

#endif

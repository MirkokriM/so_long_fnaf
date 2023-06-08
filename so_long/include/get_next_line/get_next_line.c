/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:23:30 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/30 18:00:12 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int     i = 0;
    int     rd = 0;
    char    c;
    char    *buff = malloc(100000);
    
    if (BUFFER_SIZE <= 0)
        return (NULL);
    while ((rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buff[i++] = c;
        if (c == '\n')
            break ;
    }
    buff[i] =  '\0';
    if (rd == -1 || i == 0 || (!buff[i - 1] && !rd))
        return (free(buff), NULL);
    return(buff);
}
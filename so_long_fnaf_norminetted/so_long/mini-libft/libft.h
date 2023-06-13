/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:51:07 by mivendit          #+#    #+#             */
/*   Updated: 2023/05/04 21:41:22 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void				ft_bzero(void *s, size_t n);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
void				ft_putstr(char const *s);
int					ft_putchar(char c);
int					ft_strcmp(const char *s1, const char *s2);

#endif

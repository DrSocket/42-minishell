/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:55:21 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/03/16 18:55:21 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE	1

int				get_next_line(int fd, char **line);
int				ft_check_error(int fd, char **str, char **line);
int				ft_newline(char *str);
char			*ft_readline(int fd, char *str);
void			ft_buffer_cpy(char **str, int size_line);

size_t			ft_strlen(char const *str);
char			*ft_subnull(void);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif

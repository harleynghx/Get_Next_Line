/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:43:29 by hang              #+#    #+#             */
/*   Updated: 2024/01/19 11:08:01 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
char	*get_next_line(int fd);
char	*readnjoin(int fd, char *left_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);
char	*cleanline(char *left_str);
char	*delete_upto_nl(char *left_str);
#endif

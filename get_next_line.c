/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:43:27 by hang              #+#    #+#             */
/*   Updated: 2024/01/19 11:08:06 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readnjoin(int fd, char *fd_str)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(fd_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		fd_str = ft_strjoin(fd_str, buff);
	}
	free(buff);
	return (fd_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*fd_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	fd_str = readnjoin(fd, fd_str);
	if (!fd_str)
		return (NULL);
	line = cleanline(fd_str);
	fd_str = delete_upto_nl(fd_str);
	return (line);
}
// #include <fcntl.h>
//  int	main(void)
//  {
//  	int		fd;
//     fd = open("mytest.txt", O_RDONLY);
//  	printf("%s", get_next_line(fd));
//  	// printf("%s", get_next_line(fd));
//  	// printf("%s", get_next_line(fd));
//  	// printf("%s", get_next_line(fd));
//  	// printf("%s", get_next_line(fd));
//  	// printf("%s", get_next_line(fd));
//  }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:43:27 by hang              #+#    #+#             */
/*   Updated: 2024/01/09 08:53:57 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
		// printf("\nleft_str =\n%s\n\n", left_str);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char *line;
	static char *left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
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
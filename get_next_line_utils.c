/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:32:33 by hang              #+#    #+#             */
/*   Updated: 2024/01/19 11:06:06 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *fd_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	if (!fd_str)
	{
		fd_str = (char *)malloc(1 * sizeof(char));
		fd_str[0] = '\0';
	}
	if (!fd_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(fd_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	if (fd_str)
		while (fd_str[++i])
			str[i] = fd_str[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	free(fd_str);
	return (str);
}

char	*cleanline(char *fd_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!fd_str[i])
		return (NULL);
	while (fd_str[i] && fd_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (fd_str[i] && fd_str[i] != '\n')
	{
		str[i] = fd_str[i];
		i++;
	}
	if (fd_str[i] == '\n')
	{
		str[i] = fd_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*delete_upto_nl(char *fd_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (fd_str[i] && fd_str[i] != '\n')
		i++;
	if (!fd_str[i])
	{
		free(fd_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(fd_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (fd_str[i])
		str[j++] = fd_str[i++];
	str[j] = '\0';
	free(fd_str);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:21:58 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 15:59:36 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_get_next_line(char *s1, char *s2)
{
	size_t	i1;
	size_t	i2;
	char	*s3;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	s3 = ft_calloc(i1 + i2 + 1, 1);
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, i1);
	ft_memcpy(s3 + i1, s2, i2);
	s3[i1 + i2] = '\0';
	return (free_reset_return(s1, NULL, s3));
}

char	*free_reset_return(char *to_reset, char *reset_to, char *to_return)
{
	if (to_reset != NULL)
		free(to_reset);
	to_reset = reset_to;
	return (to_return);
}

void	update_all(char *buffer, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i] != '\0')
	{
		buffer[j] = line[i];
		line[i] = '\0';
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	bytes_read = BUFFER_SIZE;
	line = NULL;
	line = ft_strjoin_get_next_line(line, buffer);
	while (ft_strchr(buffer, '\n') == NULL && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_reset_return(line, NULL, NULL));
		buffer[bytes_read] = '\0';
		line = ft_strjoin_get_next_line(line, buffer);
		if (line == NULL)
			return (line);
	}
	if (line[0] == '\0')
		return (free_reset_return(line, NULL, NULL));
	update_all(buffer, line);
	return (line);
}

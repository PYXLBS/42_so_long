/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:21:42 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 15:59:54 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line_bonus(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	bytes_read = BUFFER_SIZE;
	line = NULL;
	line = ft_strjoin_get_next_line(line, buffer[fd]);
	while (ft_strchr(buffer[fd], '\n') == NULL && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_reset_return(line, NULL, NULL));
		buffer[fd][bytes_read] = '\0';
		line = ft_strjoin_get_next_line(line, buffer[fd]);
		if (line == NULL)
			return (line);
	}
	if (line[0] == '\0')
		return (free_reset_return(line, NULL, NULL));
	update_all(buffer[fd], line);
	return (line);
}

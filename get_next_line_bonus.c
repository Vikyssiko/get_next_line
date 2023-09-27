/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:45:05 by vkozlova          #+#    #+#             */
/*   Updated: 2023/06/16 21:45:05 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(char *str)
{
	char	*result;
	int		index;

	index = 0;
	if (ft_strlen(str) == 0)
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	if (str[index] == '\n')
		result = malloc(index + 2);
	else
		result = malloc(index + 1);
	if (!result)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != '\n')
	{
		result[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
		result[index++] = '\n';
	result[index] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*strings[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	strings[fd] = read_till_new_line(fd, strings[fd]);
	if (!strings[fd])
		return (NULL);
	line = read_line(strings[fd]);
	strings[fd] = clean(strings[fd]);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:50:07 by vkozlova          #+#    #+#             */
/*   Updated: 2023/06/14 18:50:07 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	s1_size;
	size_t	s2_size;
	int		index;

	index = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (s2_size == 0)
		return (s1);
	result = malloc(s1_size + s2_size + 1);
	if (!result)
		return (NULL);
	while (s1 && s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	if (s1)
		free(s1);
	while (*s2)
		result[index++] = *s2++;
	result[index] = '\0';
	return (result);
}

char	*read_till_new_line(int fd, char *str)
{
	int		read_bytes;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(str) && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*clean(char *str)
{
	int		new_index;
	int		index;
	char	*new_str;

	if (ft_strlen(str) == 0)
		return (NULL);
	new_index = 0;
	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (str[index] == '\n')
		index++;
	if (ft_strlen(str) - index == 0)
	{
		free(str);
		return (NULL);
	}
	new_str = malloc(ft_strlen(str) - index + 1);
	if (!new_str)
		return (NULL);
	while (str[index])
		new_str[new_index++] = str[index++];
	new_str[new_index] = '\0';
	free(str);
	return (new_str);
}

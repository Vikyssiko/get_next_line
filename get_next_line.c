/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:22:38 by vkozlova          #+#    #+#             */
/*   Updated: 2023/06/14 18:40:12 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

//#include <fcntl.h>
//
//int main()
//{
//	int fd = open("one_line_no_nl.txt", O_RDONLY);
//	char *str1 = get_next_line(fd);
//	printf("line1: %s", str1);
//	free(str1);
//	char *str2 = get_next_line(fd);
//	printf("line2: %s", str2);
//	free(str2);
//	char *str3 = get_next_line(fd);
//	printf("line3: %s", str3);
//	free(str3);
//	char *str4 = get_next_line(fd);
//	printf("line4: %s", str4);
//	free(str4);
//	char *str5 = get_next_line(fd);
//	printf("line5: %s", str5);
//	free(str5);
//}
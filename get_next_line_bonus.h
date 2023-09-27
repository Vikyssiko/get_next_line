/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:45:49 by vkozlova          #+#    #+#             */
/*   Updated: 2023/06/16 21:45:49 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t	ft_strlen(char *s);
int		ft_strchr(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*read_till_new_line(int fd, char *str);
char	*clean(char *str);
char	*read_line(char *str);
char	*get_next_line(int fd);

#endif
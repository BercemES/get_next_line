/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekinci- <bekinci-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:33:27 by bekinci-          #+#    #+#             */
/*   Updated: 2024/11/25 13:33:27 by bekinci-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_txt(int fd, char *stack)
{
	char	*buffer;
	int		byte;

	if (!stack)
	{
		stack = malloc(sizeof(char) * 1);
		if (!stack)
			return (NULL);
		stack[0] = '\0';
	}
	byte = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(stack), NULL);
	while (!ft_strchr(stack, '\n') && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (free(buffer), free(stack), NULL);
		buffer[byte] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	free(buffer);
	return (stack);
}

char	*first_line(char *stack)
{
	int		i;
	char	*line;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next_line(char *stack)
{
	char	*lines;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\0')
		return (free(stack), NULL);
	if (stack[i] == '\n')
		i++;
	lines = (char *)malloc((ft_strlen(stack) - i + 1) * sizeof(char));
	if (!lines)
		return (free(stack), NULL);
	while (stack[i + j] != '\0')
	{
		lines[j] = stack[i + j];
		j++;
	}
	lines[j] = '\0';
	free(stack);
	return (lines);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = read_txt(fd, stack);
	if (!stack)
		return (NULL);
	line = first_line(stack);
	stack = next_line(stack);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekinci- <bekinci-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:27:56 by bekinci-          #+#    #+#             */
/*   Updated: 2024/12/03 15:33:02 by bekinci-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s, char *adds)
{
	char	*str;
	int		i;

	i = 0;
	if (!adds)
		return (s);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(adds) + 1));
	if (!str)
		return (free(s), NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	i = -1;
	while (adds[++i] != '\0')
		str[ft_strlen(s) + i] = adds[i];
	str[ft_strlen(s) + i] = '\0';
	free (s);
	return (str);
}

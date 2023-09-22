/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:58:44 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/13 01:08:33 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[1];
	char		*str;
	int			i;

	i = 1;
	str = NULL;
	if (0 > fd || fd > 1023)
		return (NULL);
	if (*buf)
	{
		ft_copy_buf(buf);
		str = ft_strjoin_gnl(str, buf);
	}
	while (i > 0 && ft_test_line(str))
	{
		i = read(fd, buf, 1);
		if (i < 1 && str && *str)
			return (str);
		buf[i] = '\0';
		str = ft_strjoin_gnl(str, buf);
	}
	if (!*str)
		return (ft_nes(str));
	return (ft_sep_line(str));
}

char	*ft_nes(char *str)
{
	free(str);
	return (NULL);
}

char	*ft_sep_line(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i] && (str[i] != '\n' ))
		i++;
	if (str[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (dest);
	i = 0;
	while (str[i] && str[i] != '\n' )
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dest[i] = str[i];
		i++;
	}
	free(str);
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsugimot <tsugimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:04:36 by tsugimot          #+#    #+#             */
/*   Updated: 2026/05/07 15:33:21 by tsugimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SZIE 42

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*head;

	head = dst;
	while (*src && len--)
		*dst++ = *src++;
	return (head);
}

char	ft_get_c(int fd)
{
	static char str[BUFFER_SIZE];
	static int	n;
	static int	i;
	static char	c;

	if (i > n || !*str)
	{
		n = read (fd, str, BUFFER_SIZE);
		if (n == -1 || n == 0)
			return (-1);
		i = 0;
	}
	c = str[i];
	i++;
	return (c);
}

char	*ft_put_c(char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen (str) + 2));
	if (!new)
	{
		free (str);
		return (NULL);
	}
	while (str[i])
		i++;
	ft_strncpy (new, str, i);
	new[i] = c;
	new[i + 1] = '\0';
	free (str);
	return (new);
}

char	*get_next_line(int fd)
{
	int		n;
	char	c;
	char	*str;

	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	while (1)
	{
		c = ft_get_c (fd);
		if (c == -1)
			return (NULL);
		str = ft_put_c (str, c);
		if (!str)
			return (NULL);
		if (c == '\n')
			break;
	}
	return (str);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd = open ("text1", O_RDONLY);
	char *str = get_next_line (fd);
	char *str1 = get_next_line (fd);
	char *str2 = get_next_line (fd);
	printf("%s", str);
	printf("%s", str1);
	printf("%s", str2);
}

// int	main(void)
// {
// 	/*test of ft_get_c*/
// 	int	fd = open ("text1", O_RDONLY);
// 	char c1 = ft_get_c (fd);
// 	char c2 = ft_get_c (fd);
// 	char c3 = ft_get_c (fd);
// 	char c4 = ft_get_c (fd);
// 	char c5 = ft_get_c (fd);
// 	char c6 = ft_get_c (fd);
// 	char c7 = ft_get_c (fd);
// 	char c8 = ft_get_c (fd);
// 	char c9 = ft_get_c (fd);
// 	char c10 = ft_get_c (fd);
// 	char c11 = ft_get_c (fd);
// 	char c12 = ft_get_c (fd);
// 	char c13 = ft_get_c (fd);
// 	char c14 = ft_get_c (fd);
// 	char c15 = ft_get_c (fd);
// 	char c16 = ft_get_c (fd);
// 	char c17 = ft_get_c (fd);
// 	char c18 = ft_get_c (fd);
// 	char c19 = ft_get_c (fd);
// 	char c20 = ft_get_c (fd);
// 	char c21 = ft_get_c (fd);
// 	char c22 = ft_get_c (fd);
// 	char c23 = ft_get_c (fd);
// 	printf("--test:getc--\n");
// 	printf("%c", c1);
// 	printf("%c", c2);
// 	printf("%c", c3);
// 	printf("%c", c4);
// 	printf("%c", c5);
// 	printf("%c", c6);
// 	printf("%c", c7);
// 	printf("%c", c8);
// 	printf("%c", c9);
// 	printf("%c", c10);
// 	printf("%c", c11);
// 	printf("%c", c12);
// 	printf("%c", c13);
// 	printf("%c", c14);
// 	printf("%c", c15);
// 	printf("%c", c16);
// 	printf("%c", c17);
// 	printf("%c", c18);
// 	printf("%c", c19);
// 	printf("%c", c20);
// 	printf("%c", c21);
// 	printf("%c", c22);
// 	printf("%c", c23);
// 	printf("\n\n");

// 	/*test of ft_put_c*/
// 	char	*str = malloc(sizeof(char));
// 	str[0] = '\0';
// 	char	*str1 = ft_put_c (str, c1);
// 	char	*str2 = ft_put_c (str1, c2);
// 	char	*str3 = ft_put_c (str2, c3);
// 	char	*str4 = ft_put_c (str3, c4);
// 	char	*str5 = ft_put_c (str4, c5);
// 	char	*str6 = ft_put_c (str5, c6);
// 	char	*str7 = ft_put_c (str6, c7);
// 	printf("--test:putc--\n");
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	printf("%s\n", str3);
// 	printf("%s\n", str4);
// 	printf("%s\n", str5);
// 	printf("%s\n", str6);
// 	printf("%s\n", str7);
	
// 	return (0);
// }

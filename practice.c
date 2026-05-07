#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFF_SIZE
#define BUFF_SIZE 42
#endif

typedef struct 		s_str
{
	unsigned char	*str;
	size_t			len;
	size_t			capa;
}					t_str;

int	ft_getc(int fd)
{
	static char	buf[BUFF_SIZE];
	static char	*bufp;
	static int	n;

	if (n == 0)
	{
		n = read (fd, buf, BUFF_SIZE);
		bufp = buf;
	}
	if (n-- > 0)
		return ((int)*bufp++);
	if (n == -1)
		return (-1);
	return (EOF);
}

int	ft_putc(t_str *str, unsigned char c)
{
	size_t			new_capa;
	unsigned char	*new_str;
	size_t			i;
	if (str->len + 1 > str->capa)
	{
		if (str->capa == 0)
			new_capa = BUFF_SIZE;
		else
			new_capa = str->capa * 2;
		new_str = (unsigned char *)malloc(sizeof(unsigned char) * new_capa);
		if (!new_str)
			return (-1);
		i = 0;
		while (i < str->len)
		{
			new_str[i] = str->str[i];
			i++;
		}
		free (str->str);
		str->str = new_str;
		str->capa = new_capa;
	}
	str->str[str->len] = c;
	str->len++;
	return (0);
}

//BUFF_SIZEが結構int_maxと同じ桁くらい大きくなるとエラーが出る

char	*get_next_line(int fd)
{
	t_str	ret;
	char	c;

	ret.str = NULL;
	ret.len = 0;
	ret.capa = 0;

	while (1)
	{
		c = ft_getc (fd);
		if (c == EOF)
			break ;
		if (c == -1)
			return (NULL);
		ft_putc (&ret, c);
		if (c == '\n')
			break ;
	}
	if (ret.len > 0)
		ft_putc (&ret, '\0');
	return ((char *)ret.str);
}

int	main(void)
{
	char	*l0;
	char	*l1;
	char	*l2;
	char	*r;
	int fd = open ("text", O_RDONLY);
	int fd1 = open ("text1", O_RDONLY);
	l0 = get_next_line (fd);
	l1 = get_next_line (fd);
	// r = get_next_line (fd1);
	l2 = get_next_line (fd);
	
	printf("%s", l0);
	printf("%s", l1);
	printf("%s", l2);
	// printf("%s", r);
}

// int	main(void)
// {
// 	int c;
// 	int fd = open ("text", O_RDONLY);
// 	while (1)
// 	{
// 		c = ft_getc (fd);
// 		if (c == EOF)
// 			break ;
// 		printf("%c", c);
// 	}
// 	close (fd);
// 	return (0);
// }




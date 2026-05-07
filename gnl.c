#include "get_next_line.h"

void	ft_strcpy(char *s1, char *s2)
{
	while (*s2)
		*s1++ = *s2++;
}

int		ft_ex_break(char *buf)
{
	if (!buf)
		return (0);
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

char	*ft_afbr(char *buf)
{
	char	*re;
	char	*head;
	int		i;
	int		len_re;

	i = 0;
	len_re = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	while (buf[i++])
		len_re ++;
	re = (char *)malloc(sizeof(char) * (len_re + 1));
	if (!re)
		return (NULL);
	head = re;
	while (*buf && *buf != '\n')
		buf++;
	while (*buf)
		*re++ = *buf++;
	*re = '\0';
	return (re);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*line;
	char	*head;

	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1] && s1[len_s1] != '\n')
		len_s1++;
	while (s2[len_s2] && s2[len_s2] != '\n')
		len_s2++;
	line = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!line)
		return (NULL);
	head = line;
	while (*s1 && *s1 != '\n')
		*line++ = *s1++;
	while (*s2 && *s2 != '\n')
		*line++ = *s2++;
	*line = '\0';
	return (head);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	static char	*buf2;
	int 		buf_len;
	char		*line;

	if (!buf)
	{
		buf = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1));
		buf2 = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1));
	}
	if (!buf || !buf2)
		return (NULL);
	buf_len = 0;
	line = (char *)malloc(sizeof(char) * 1);
	*line = '\0';
	while (!ft_ex_break (line))
	{
		buf_len = read (fd, &buf[buf_len], BUFFER_SIZE );
		buf[buf_len] = '\0';
		line = ft_strjoin (line, buf2);
		line = ft_strjoin (line , buf);
		free (buf);
		free (buf2);
	}
	buf2 = ft_afbr (buf);
	return (line);
}

#include <stdio.h>
int	main(void)
{
	int fd = open ("get_next_line.h", O_RDONLY);
	char *line = get_next_line (fd);
	printf("%s", line);
}
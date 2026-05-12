/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsugimot <tsugimot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:39:14 by tsugimot          #+#    #+#             */
/*   Updated: 2026/05/12 12:21:53 by tsugimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		ft_get_c(int fd);
char	*ft_put_c(char *str, char c);
char	*free_and_return(char **str);
char	*get_next_line(int fd);

#endif

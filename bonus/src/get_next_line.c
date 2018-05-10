/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** 2
*/

#include "get_next_line.h"

int my_strlen_get(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

char	*my_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}

char *put_my_char(char *line, char *buf, int len, int ptr)
{
	char *tmp = malloc(sizeof(char) * (len + 2));

	if (len != 0)
		tmp = my_strcpy(tmp, line);
	tmp[len] = buf[ptr];
	tmp[len +1] = '\0';
	return (tmp);
}

char *get_next_line(int fd)
{
	static char buf[READ_SIZE];
	char *line = malloc(sizeof(char) * 1);
	static int ptr = 0;
	static int bytes = 0;
	static int len = 0;

	while (1) {
		if (ptr == 0)
			bytes = read(fd, buf, READ_SIZE);
		if (ptr == 0 && bytes < 1)
			return (NULL);
		while (buf[ptr] != '\n' && ptr < bytes) {
			len = my_strlen_get(line);
			line = put_my_char(line, buf, len, ptr);
			ptr += 1;
		}
		if (buf[ptr] == '\n') {
			ptr += 1;
			return (line);
		}
		if (ptr >= bytes)
			ptr = 0;
	}
}

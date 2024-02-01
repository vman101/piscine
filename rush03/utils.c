/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvobis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:33:51 by vvobis            #+#    #+#             */
/*   Updated: 2024/01/29 16:13:25 by vvobis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h" 
#include <unistd.h>

void r_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void r_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		r_putchar(str[i++]);
}

void r_puterr(char *err)
{
	while (*err)
		write(STDERR_FILENO, err++, 1);
}

int r_putline_db(t_line *line)
{
	r_putstr(line->data_desc);
	r_putstr(line->filler);
	r_putstr(line->data);
	return (1);
}

int r_print_parsed_input_db(char **input)
{
	int i;

	i = 0;
	while (input[i])
	{
		r_putchar(i + '0');
		r_putstr(": ");
		r_putstr(input[i++]);
		r_putchar(0x0a);
	}
	return (1);
}

int r_combined_strlen(int **str)
{
	int i;
	int j;
	int combined_strlen;

	i = 0;
	combined_strlen = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			j++;
			combined_strlen++;
		}
		i++;
	}
	return (combined_strlen);
}


void r_convert_parsed_input(int **parsed_input)
{
	int **block_ptr;
	int div;
	int i;
	int j = 0;

	i = r_combined_strlen(parsed_input) / 3;
	block_ptr = &parsed_input[0];
	while (i > 1)
	{
		div = 100;
		while (j < 3)
		{
			**block_ptr -= 48;
			**block_ptr *= div;
			printf("block_ptr: %d\n", **block_ptr);
			*block_ptr += 1;
			if (div != 1)
				div /= 10;
			j++;
		}
		i--;
	}
}

int **r_parsed_input_create(char *input)
{
	int **parsed_input;

	parsed_input = r_parsed_input_to_int(input);
	printf("parsed 123 befor conv: %d\n", **parsed_input);
	//r_convert_parsed_input(parsed_input);
	printf("before return\n");
	return (parsed_input);
}

int **r_parsed_input_to_int(char *input)
{
	int i;
	int **parsed_input;
	int input_length;
	int j;

	i = 0;
	while (input[i])
		i++;
	parsed_input = (int **)malloc(sizeof(*parsed_input) * (i / 3) + 1);
	input_length = i / 3;
	i = 0;
	while (i < input_length)
	{
		j = 0;
		parsed_input[i] = (int *)malloc(sizeof(**parsed_input) * 4);
		while (j < 3)
		{
			parsed_input[i][j] = *input++;
			printf("parsed input[%d][%d] after: %d\n", i, j, parsed_input[i][j]);
			j++;
			parsed_input[i][j] = '\0';
		}
		i++;
	}
	return (parsed_input);
}

void r_parsed_input_free(int **parsed_input)
{
	int i;

	i = 0;
	while (parsed_input[i])
		free(parsed_input[i++]);
	free(parsed_input);
}

void r_convert_under_100(int *result, int nb)
{
	if (nb > 99)
	{
		*result++ = nb / 100;
		nb = nb % 100;
	}
	if (nb > 19)
	{
		*result++ = nb / 10;
		nb = nb % 10;
	}
	else if (nb < 19 && nb > 10)
	{
		*result++ = nb;
		return ;
	}
	*result = nb;
}

int r_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int	r_is_negative(char *str, int *i)
{
	int	counter;

	counter = 0;
	while ((str[*i] >= 9 && str[*i] <= 13)
		|| str[*i] == 32 || str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			counter++;
		*i += 1;
	}
	return (counter % 2);
}

int	r_atoi(char *str)
{
	int		i;
	int		res;
	char	flag;

	flag = 1;
	res = 0;
	i = 0;
	if (r_is_negative(str, &i))
		flag = -1;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i]) - '0';
		i++;
	}
	return (flag * res);
}

int r_get_max_line_size(char *path)
{
	int fdesc;
	int i;
	int size;
	char c;

	fdesc = open(path, O_RDONLY);
	size = 0;
	i = 0;
	while (read(fdesc, &c, 1))
	{
		if(c == 0x0a)
			i = 0;
		if (i > size)
			size = i;
		i++;
	}
	close(fdesc);
	return (size + 1);
}

int r_read_line_parsed(t_dict *dict)
{
	int len;
	char *buf;
	int max_line_size;
	int i;

	max_line_size = r_get_max_line_size("numbers.dict");
	printf("max line: %d\n", max_line_size);
	printf("dict entry count: %d\n", dict->entry_count);
	dict->file_descriptor = open("numbers.dict", O_RDONLY);
	buf = (char *)malloc(sizeof(*buf) * max_line_size);
	i = 0;
	while (i < dict->entry_count)
	{
		len = 0;
		while (buf[len - 1] != 0x0a)
		{
			read(dict->file_descriptor, &buf[len], 1);
			len++;
		}
		buf[len] = '\0';
		if(!(dict->entries[i] = r_parse_file_line(buf, len)))
		{
			close(dict->file_descriptor);
			return (0);
		}
		i++;
	}
	close(dict->file_descriptor);
	free(buf);
	return (i);
}

t_line *r_parse_file_line(char *read_line, int len)
{
	int i;
	int j;
	t_line *parsed_line;

	i = 0;
	j = 0;
	if (!(parsed_line = r_line_create(len)))
		return (0);
	while (read_line[i] >= 48 && read_line[i] <= 57)
		parsed_line->data_desc[j++] = read_line[i++];
	parsed_line->data_desc[j] = 0;
	j = 0;
	while (read_line[i] == 0x20 || read_line[i] == 0x3a)
		parsed_line->filler[j++] = read_line[i++];
	parsed_line->filler[j] = 0;
	j = 0;
	while (read_line[i - 1] != 0x0a)
		parsed_line->data[j++] = read_line[i++];
	parsed_line->data[j] = 0;
	return (parsed_line);
}

int r_get_line_count(int fdesc)
{
	char c;
	char i;

	c = 1;
	i = 0;
	while (read(fdesc, &c, 1))
	{
		if (c == 0x0a)
			i++;
	}
	return (i);
}

t_line *r_line_create(int size)
{
	t_line *tmp_line;

	if(!(tmp_line = (t_line *)malloc(sizeof(*tmp_line))))
	{
		r_puterr("Dict Error!\n");
		return (0);
	}
	if(!(tmp_line->data_desc = (char *)malloc(size)))
	{
		r_puterr("Dict Error!\n");
		return (0);
	}
	if(!(tmp_line->filler = (char *)malloc(size)))
	{
		r_puterr("Dict Error!\n");
		return (0);
	}
	if(!(tmp_line->data = (char *)malloc(size)))
	{
		r_puterr("Dict Error!\n");
		return (0);
	}
	return (tmp_line);
}

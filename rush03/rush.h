/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvobis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:14:41 by vvobis            #+#    #+#             */
/*   Updated: 2024/01/29 16:14:27 by vvobis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct r_file_line
{
	char *data_desc;
	char *filler;
	char *data;
} t_line;

typedef struct dictionairy
{
	t_line **entries;
	char *filepath;
	int file_descriptor;
	int entry_count;
} t_dict;

/* Utils */
void r_putchar(char c);									// Print single char
void r_putstr(char *str);								// Print string
void r_puterr(char *err);
int r_strncpy(char *dest, char *src, int n);
int r_putline_db(t_line *line);
int r_strlen(char *str);								// Return string length
int r_read_line_parsed(t_dict *dict);					// Read input into string, return length
int r_get_line_count(int fdesc);
int	r_atoi(char *str);
int	r_is_negative(char *str, int *i);
int	**r_parsed_input_create(char *input);
int **r_parsed_input_to_int(char *input);
void r_convert_under_100(int *result, int nb);
void r_parsed_input_free(int **parsed_input);

/* Line Parsing */
t_line *r_parse_file_line(char *read_line, int len);	// Parse read line from file into sections
t_line *r_line_create(int size);
int r_line_destroy(t_line *line);

/* Dictionairy Initiation and Destruction */
t_dict *r_dict_create();					// allocate memory to t_dict pointer
int r_dict_destroy(t_dict *dict);						// deallocate memory from t_dict pointer

/* File Handeling */
int r_dict_file_open();						// Open .dict file
int r_dict_file_close(int *fp);							// Close .dict file
void r_dict_file_read(t_dict dest_dict);				// Read from .dict file

void r_dict_file_parse(t_dict *dest_dict, int fdesc);	// Parse file lines

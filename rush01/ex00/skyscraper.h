/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvobis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:58:06 by vvobis            #+#    #+#             */
/*   Updated: 2024/01/21 13:00:13 by vvobis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define N 4

typedef enum ERROR
{
	INV_IN,
	NO_PAT,
	SUCC,
}	t_ERROR;

void	putchar(char c);
void	putstr(char *str);

int		goto_zero(int grid[N][N], int *row, int *col);

int		grid_is_valid(int grid[N][N], int *clue);
int		is_valid_top(int grid[N][N], int col, int num);
int		is_valid_bot(int grid[N][N], int col, int num);
int		is_valid_left(int grid[N][N], int row, int num);
int		is_valid_right(int grid[N][N], int row, int num);

int		slot_is_safe(int grid[N][N], int row, int col, int num);
int		col_is_safe(int grid[N][N], int col, int num);
int		row_is_safe(int grid[N][N], int row, int num);

int		backtrack(int grid[N][N], int *clue);

void	print_grid(int grid[N][N]);

void	va_strncpy(char *dest, char *src, int size);
int		print_error(int err_code);

int		user_input_check(int input_count, char *input);
int		*user_input_handle(int input_count, char *input, int pattern[16]);

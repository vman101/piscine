/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvobis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:57:43 by vvobis            #+#    #+#             */
/*   Updated: 2024/01/21 13:02:49 by vvobis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	is_valid_top(int grid[N][N], int col, int num)
{
	int	row;
	int	c;
	int	max;

	c = 1;
	row = 0;
	max = grid[row][col];
	while (row < N)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			c++;
		}
		row++;
	}
	if (c == num)
		return (1);
	return (0);
}

int	is_valid_bot(int grid[N][N], int col, int num)
{
	int	row;
	int	c;
	int	max;

	c = 1;
	row = N - 1;
	max = grid[row][col];
	while (row >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			c++;
		}
		row--;
	}
	if (c == num)
		return (1);
	return (0);
}

int	is_valid_left(int grid[N][N], int row, int num)
{
	int	col;
	int	c;
	int	max;

	c = 1;
	col = 0;
	max = grid[row][col];
	while (col < N)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			c++;
		}
		col++;
	}
	if (c == num)
		return (1);
	return (0);
}

int	is_valid_right(int grid[N][N], int row, int num)
{
	int	col;
	int	c;
	int	max;

	c = 1;
	col = N - 1;
	max = grid[row][col];
	while (col >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			c++;
		}
		col--;
	}
	if (c == num)
		return (1);
	return (0);
}

int	grid_is_valid(int grid[N][N], int *clue)
{
	int	i;

	i = 0;
	while (clue[i])
	{
		if (i >= 0 && i <= 3)
			if (!is_valid_top(grid, i, clue[i]))
				return (0);
		if (i >= N && i <= 7)
			if (!is_valid_bot(grid, i - N, clue[i]))
				return (0);
		if (i >= (N * 2) && i <= 11)
			if (!is_valid_left(grid, i - (N * 2), clue[i]))
				return (0);
		if (i >= (N * 3) && i <= 15)
			if (!is_valid_right(grid, i - (N * 3), clue[i]))
				return (0);
		i++;
	}
	return (1);
}

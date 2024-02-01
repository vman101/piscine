/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvobis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:50:30 by vvobis            #+#    #+#             */
/*   Updated: 2024/01/21 11:12:48 by vvobis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	goto_zero(int grid[N][N], int *row, int *col)
{
	*row = 0;
	*col = 0;
	while (*row < N)
	{
		while (*col < N)
		{
			if (grid[*row][*col] == 0)
				return (1);
			*col += 1;
		}
		*col = 0;
		*row += 1;
	}
	return (0);
}

int	col_is_safe(int grid[N][N], int col, int num)
{
	int	row;

	row = 0;
	while (row < N)
	{
		if (grid[row][col] == num)
			return (0);
		row++;
	}
	return (1);
}

int	row_is_safe(int grid[N][N], int row, int num)
{
	int	col;

	col = 0;
	while (col < N)
	{
		if (grid[row][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int	slot_is_safe(int grid[N][N], int row, int col, int num)
{
	if (!row_is_safe(grid, row, num))
		return (0);
	if (!col_is_safe(grid, col, num))
		return (0);
	return (1);
}

int	backtrack(int grid[N][N], int *clue)
{
	int	i;
	int	row;
	int	col;

	i = 1;
	if (!goto_zero(grid, &row, &col) && grid_is_valid(grid, clue))
		return (1);
	while (i <= N)
	{
		if (slot_is_safe(grid, row, col, i))
		{
			grid[row][col] = i;
			if (backtrack(grid, clue))
				return (1);
			grid[row][col] = 0;
		}
		i++;
	}
	return (0);
}

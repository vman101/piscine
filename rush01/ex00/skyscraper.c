/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvobis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:20:31 by vvobis            #+#    #+#             */
/*   Updated: 2024/01/21 13:15:08 by vvobis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

void	init_grid(int grid[N][N])
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	grid[N][N]; 
	int	pattern[16];
	int i;

	i = 0;
	init_grid(grid);
	if (!user_input_handle(argc, argv[argc - 1], pattern))
		return (1);
	if (!backtrack(grid, pattern))
	{
		print_error(NO_PAT);
		return (1);
	}
	else
	{
		print_error(SUCC);
		putchar('\n');
		print_grid(grid);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvobis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:48:39 by vvobis            #+#    #+#             */
/*   Updated: 2024/01/21 13:31:48 by vvobis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		putchar(str[i++]);
}

void	print_grid(int grid[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			putchar(grid[i][j] + '0');
			putchar(' ');
			j++;
		}
		putchar('\n');
		i++;
	}
}

int	user_input_check(int input_count, char *input)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (input_count != 2)
	{
		print_error(INV_IN);
		return (0);
	}
	while (input[j])
	{
		if (input[j] >= '1' && input[j] <= '4')
			i++;
		j++;
	}
	if (i == 16)
		return (1);
	return (print_error(INV_IN));
}

int	*user_input_handle(int input_count, char *input, int pattern[16])
{
	int	i;

	if (!user_input_check(input_count, input))
		return (0);
	i = 0;
	while (input[i])
	{
		if (input[i] >= '1' && input[i] <= '4')
			pattern[i] = input[i] - '0';
		i++;
	}
	pattern[i] = '\0';
	return (pattern);
}

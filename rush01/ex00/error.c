/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvobis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:10:52 by vvobis            #+#    #+#             */
/*   Updated: 2024/01/21 12:40:42 by vvobis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

void	va_strncpy(char *dest, char *src, int size)
{
	int i;

	i = 0;
	while (src[i] != 0 || i <= size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	puterror(char *err)
{
	int i;

	i = 0;
	while (err[i] != '\0')
	{
		write(2, &err[i], 1);
		i++;
	}
}

int	print_error(int err_code)
{
	char	err_message[3][50];

	va_strncpy(err_message[0], "Invalid Input! Please Try Again...\n", 40);
	va_strncpy(err_message[1],
		"No Pattern Found! Please Check Your Input...\n", 40);
	va_strncpy(err_message[2], "The Puzzle Was Solved Successfully!\n", 40);
	putstr(err_message[err_code]);
	putstr("Error Code: ");
	putchar(0x30 + err_code);
	return (err_code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvobis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:39:16 by vvobis            #+#    #+#             */
/*   Updated: 2024/01/29 13:55:07 by vvobis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int r_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char *r_itoa(int nb)
{
	int nb_size;
	int i;
	char *str;
	int div = 1;

	i = 0;
	nb_size = nb;
	while(nb_size > 0)
	{
		nb_size /= 10;
		i++;
	}
	str = (char *)malloc(sizeof(*str) * i + 1);
	//printf("%d\n", i);
	while (i > 0)
	{
		*str++ = (nb / div) + '0';
		nb -= (nb / div) * div;
		div /= 10;
		i--;
	}
	str[i] = 0;
	return (str);
}

char **conver_ints(int **n)
{
	char **res;

	res = malloc(sizeof(*res) * 4);
	*n[0] -= 48;
	*n[1] -= 48;
	*n[2] -= 48;
	*res++ = r_itoa(*n[0]);
	*res++ = r_itoa(100);
	if(*n[1] < 2)
	{
		*n[1] = (*n[1] * 10) + *n[2];
		*res++ = r_itoa(*n[1]);
		return (res);
	}
	else 
	{
		*res++ = r_itoa(*n[1] * 10);
		*res = r_itoa(*n[2]);
	}
	return (res);
}


int main()
{
	t_dict *dict = r_dict_create();
	char *input = "223456123";	
	int **input_parsed = r_parsed_input_create(input);
	int i = 0;
	int j = 0;

	r_read_line_parsed(dict);
	while (i < dict->entry_count)
	{
		if (!r_strcmp((char *)&(**input_parsed), dict->entries[i]->data_desc))
		{
			r_putstr(dict->entries[i]->data);
			i = 0;
			j++;
			(*input_parsed)++;
			if (j == 3)
			{
				input_parsed++;
				j = 0;
			}
		}
		i++;
	}

	r_parsed_input_free(input_parsed);
	r_dict_destroy(dict);
}

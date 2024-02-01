/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvobis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:29:48 by vvobis            #+#    #+#             */
/*   Updated: 2024/01/29 13:56:04 by vvobis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_dict *r_dict_create()
{
	t_dict *dict_tmp;

	dict_tmp = (t_dict *)malloc(sizeof(*dict_tmp));
	dict_tmp->file_descriptor = open("numbers.dict", O_RDONLY);
	dict_tmp->entry_count = r_get_line_count(dict_tmp->file_descriptor);
	dict_tmp->entries = (t_line **)malloc(sizeof(dict_tmp->entries) * dict_tmp->entry_count);
	close(dict_tmp->file_descriptor);
	return (dict_tmp);
}

int r_dict_destroy(t_dict *dict)
{
	int i;

	i = 0;
	while (i < dict->entry_count)
		r_line_destroy(dict->entries[i++]);
	free(dict->entries);
	free(dict);
	if (!dict)
		return (1);
	return (0);
}

int r_line_destroy(t_line *line)
{
	if (line)
	{
		free(line->data_desc);
		free(line->filler);
		free(line->data);
		free(line);
		return (1);
	}
	return (0);
}

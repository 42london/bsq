/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sq_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:06:23 by abelov            #+#    #+#             */
/*   Updated: 2023/10/24 17:06:25 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sq_utils.h"
#include "string_utils.h"


t_baguette	fill_all_sizes(t_baguette b)
{
	int	i;

	i = 0;
	while (i < b.map_arr_size)
	{
		set_size(&b.map[i], b);
		if (b.map[i].size > b.solution.size)
			b.solution = b.map[i];
		i++;
	}
	return (b);
}

t_baguette	get_solution(t_baguette b)
{
	t_baguette		baguette;
	t_sq_element	s;
	t_sq_element	temp;

	baguette = fill_all_sizes(b);
	if (baguette.solution.is_obstacle == false)
	{
		s = baguette.solution;
		temp = create_element(s.pos.x - (s.size - 1), s.pos.y - (s.size - 1), s.size, s.is_obstacle);
		baguette.solution = temp;
	}
	return (b);
}

char	*serializer(t_baguette b)
{
	int		i;
	char	*str;
	char	c;

	i = 0;
	str = ft_empty_string(b.map_arr_size + b.size.y + 1);
	while (i < b.map_arr_size)
	{
		c = '.';
		if (b.map[i].is_obstacle)
			c = 'o';
		else if (b.map[i].is_obstacle)
			c = 'x';
		ft_strlcat(str, &c, 1);
		i++;
	}
	return (str);
}

char	*serial_killer(t_baguette baguette)
{
	(void)baguette;
	return (NULL);
}

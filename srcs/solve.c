/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:44:40 by xzhu              #+#    #+#             */
/*   Updated: 2020/03/03 21:44:41 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	try_piece(t_f *f, int m_x, int m_y)
{
	int x;
	int y;
	int hit;

	hit = 0;
	y = -1;
	while (++y < (int)f->piece_h)
	{
		x = -1;
		while (++x < (int)f->piece_w)
		{
			if (f->piece[y][x] == '*')
			{
				if (x + m_x >= (int)f->map_w || y + m_y >= (int)f->map_h)
					return (-1);
				else if (f->map[y + m_y][x + m_x] == f->symbol ||
						f->map[y + m_y][x + m_x] == f->symbol + 32)
					++hit;
				else if (f->map[y + m_y][x + m_x] != '.')
					return (-1);
			}
		}
	}
	return (!(hit == 1));
}

int			try_map(t_f *f)
{
	int x;
	int y;

	y = -1;
	while (++y < (int)f->map_h)
	{
		x = -1;
		while (++x < (int)f->map_w)
		{
			if (!try_piece(f, x, y))
			{
				ft_printf("%d %d\n", y, x);
				return (0);
			}
		}
	}
	ft_printf("%d %d\n", -1, -1);
	return (-1);
}

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
	t_p cur;
	int hit;

	hit = 0;
	cur.y = 0;
	while (cur.y < f->piece_h)
	{
		cur.x = 0;
		while (cur.x < f->piece_w)
		{
			if (f->piece[cur.y][cur.x] == '*')
			{
				if (f->map[(cur.y + m_y + f->map_h) % f->map_h]
					[(cur.x + m_x + f->map_w) % f->map_w] == f->symbol ||
					f->map[(cur.y + m_y + f->map_h) % f->map_h]
					[(cur.x + m_x + f->map_w) % f->map_w] == f->symbol + 32)
					++hit;
				else if (f->map[(cur.y + m_y + f->map_h) % f->map_h]
						[(cur.x + m_x + f->map_w) % f->map_w] != '.')
					return (-1);
			}
			++cur.x;
		}
		++cur.y;
	}
	return (!(hit == 1));
}

int			try_map(t_f *f)
{
	t_p cur;

	f->fit_count = 0;
	if (!f->fits)
		f->fits = ft_memalloc(sizeof(t_h) * f->map_w * f->map_h);
	cur.y = 0 - f->piece_h;
	while (cur.y < f->map_h + f->piece_h)
	{
		cur.x = 0 - f->piece_w;
		while (cur.x < f->map_w + f->piece_w)
		{
			if (!try_piece(f, cur.x, cur.y))
			{
				f->fits[f->fit_count].avaliable = 1;
				f->fits[f->fit_count].p.x = cur.x;
				f->fits[f->fit_count].p.y = cur.y;
				f->fit_count++;
			}
			++cur.x;
		}
		++cur.y;
	}
	f->fits[f->fit_count].avaliable = 0;
	if (f->fit_count == 0)
		ft_printf("%d %d\n", -1, -1);
	else
	{
		// ft_printf("%d %d\n", f->fits[f->fit_count - 1].p.y, f->fits[f->fit_count - 1].p.x);
		cur.y = f->fits[0].p.y >= 0 ? f->fits[0].p.y % f->map_h : f->fits[0].p.y;
		cur.x = f->fits[0].p.x >= 0 ? f->fits[0].p.x % f->map_w : f->fits[0].p.x;

		ft_printf("%d %d\n", cur.y, cur.x);
	}
	
	return (-1);
}

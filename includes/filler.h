/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:12:55 by xzhu              #+#    #+#             */
/*   Updated: 2020/02/28 21:12:57 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

typedef struct		s_point
{
	int	x;
	int	y;
}					t_p;

typedef struct		s_hit
{
	t_p				p;
	char			avaliable;

}					t_h;

typedef struct		s_filler
{
	int				player;
	char 			symbol;
	int				map_h;
	int				map_w;
	char			**map;
	int				piece_h;
	int				piece_w;
	char			**piece;
	int				piece_count;
	t_h				*fits;
	int				fit_count;
	t_p				aps_sum;
	t_p				enemy_pre;
	t_p				enemy_ppre;
}					t_f;

int					solve(t_f *f);
void				set_min_max(t_p *cur, t_p *min, t_p *max);

#endif

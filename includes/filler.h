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
	unsigned int	x;
	unsigned int	y;
}					t_p;

typedef struct		s_hit
{
	t_p				p;
	char			avaliable;

}					t_h;

typedef struct		s_filler
{
	unsigned int	player;
	char 			symbol;
	unsigned int	map_h;
	unsigned int	map_w;
	char			**map;
	unsigned int	piece_h;
	unsigned int	piece_w;
	char			**piece;
	t_h				*fits;
	unsigned int	fit_count;
}					t_f;

int					try_map (t_f *f);

#endif

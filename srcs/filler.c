/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:13:04 by xzhu              #+#    #+#             */
/*   Updated: 2020/02/28 21:13:06 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main( void )
{
	char*line;
	int fp;
	fp  = open ("data.txt", O_RDWR);

	while(get_next_line(0, &line))
		ft_putstr_fd(line,fp);

	close(fp);
	return 0;
}

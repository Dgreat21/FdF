/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:53:14 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/14 06:55:45 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	allocator(t_map map)
{
	int i;

	i = 0;
	g_map = (t_glist **)malloc((map.i) * sizeof(t_glist *));
	while (i < map.i)
	{
		g_map[i] = (t_glist *)malloc((map.j) * sizeof(t_glist));
	}
//	if (!())
//TODO:add error
//return (NULL);
}

t_map	counter(int fd)
{
	int		i, j;
	char	*line;
	t_map	map;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!i)
			j = ft_word_counter(line, ' ');
		i++;
	}
	if (!i)
	{
		ft_putendl("Something went wrong");
		exit(0);
	}
	map.i = i;
	map.j = j;
	map.x = 0;
	map.y = 0;
	(i % 2) ? map.y++;
	(j % 2) ? map.x++;
	allocator(map);
	return (map);
}

void	reader(int fd)
{
	char		**line, **stock;
	int			i, j;
	char		buf[BUFF_SIZE];
	t_map		map;

	map = counter(fd);
	read(fd, buf, BUFF_SIZE);
	stock = ft_strsplit(buf, '\n');
	i = 0;
	while (stock[i]) {
		line = ft_strsplit(stock[i], ' ');
		j = 0;
		while (line[j])
		{
			if (map.i >)
			g_map[i][j] = ft_atoi(line); //TODO: add coordinates move h/2 and l/2
			j++;
		}
		i++;
	}
}


int		main(int argc, char **argv)
{
	int			fd;
	char		*line;
	int			i;
	t_glist		*list;
	t_glist		*begin;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	&begin = &line;
	reader(fd, &list);
	free(line);
	if (argc == 2)
		close(fd);
}

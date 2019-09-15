/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:53:14 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/16 00:05:18 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	allocator(t_map map)
{
	int i, cl;

	i = 0;
	cl = 0;
	if ((g_map = (t_glist **)malloc((map.i) * sizeof(t_glist *))) == NULL)
		error_notice("Malloc error");
	while (i < map.i)
	{
		if ((g_map[i] = (t_glist *)malloc((map.j) * sizeof(t_glist))) == NULL)
		{
			while (cl < i) {
				free(g_map[cl]);
				cl++;
			}
			free(g_map);
			error_notice("Lines malloc error");
		}
		i++;
	}
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
		else if (j != ft_word_counter(line, ' '))
			error_notice("wrong coordinates number");
		i++;
	}
	if (!i)
		error_notice("no lines in the file");
	map.i = i;
	map.j = j;
	map.x = 0;
	map.y = 0;
	(i % 2) ? map.y++ : (0);
	(j % 2) ? map.x++ : (0);
	allocator(map);
	return (map);//TODO: replace gnl modulo
}

void	reader(int fd, t_map map)
{
	char		**line, **stock;
	int			i, j;
	char		buf[BUFF_SIZE];
//	t_map		map;
//
//	map = counter(fd);

	read(fd, buf, BUFF_SIZE);
	stock = ft_strsplit(buf, '\n');
	i = 0;
	vardump("i", i);
	ft_putendl(stock[0]);
	ft_putendl(stock[1]);
	ft_putendl(stock[2]);
	ft_putendl(stock[3]);
	ft_putendl(stock[4]);
	ft_putendl(stock[5]);
	ft_putendl(stock[6]);
	ft_putendl(stock[7]);
	ft_putendl(stock[8]);
	ft_putendl(stock[9]);
	ft_putendl(stock[10]);
	ft_putendl(stock[11]);
	ft_putendl(stock[1]);
	while (stock[i] != NULL)
	{
		line = ft_strsplit(stock[i], ' ');
		j = 0;
		while (line[j] != NULL)
		{

			g_map[i][j].x = j;
			g_map[i][j].y = i;
			g_map[i][j].z = ft_atoi(line[j]); //TODO: add coordinates move h/2 and l/2
			j++;
		}
		i++;
	}
}


int		main(int argc, char **argv)
{
	int			fd;
	t_map		map;

	if (argc == 1)
		error_notice("no file");
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	map = counter(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	reader(fd, map);
	if (argc == 2)
		close(fd);
}

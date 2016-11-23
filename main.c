/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:52:58 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/23 10:11:17 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"
#include <stdio.h>

char	**create_list(char *file, int i)
{
	int		num;
	char	**list;

	num = (ft_strlen(file) / 21) + 1;
	if (!list = (char **)malloc(sizeof(char *) * num))
		error;
	while (i < num)
	{
		if (!list[i] = (char *)malloc(17))
			error;
		i++;
	}
}

void	*my_realloc(void *ptr, size_t size)
{
	void	*ret;

	ret = malloc(size);
	ft_memcpy(ret, ptr, size - B_SIZE);
	free(ptr);
	return (ret);
}

char	*get(int fd, int i)
{
	char	*buff;
	int		red;

	red = 0;
	buff = (char *)malloc(22);
	ft_bzero(buff, 22);
	red = read(fd, buff, B_SIZE);
	while (red == 21)
	{
		buff = (char *)my_realloc(buff, (B_SIZE * i) + 1);
		ft_bzero(&buff[B_SIZE * (i - 1)], B_SIZE + 1);
		red = read(fd, &buff[B_SIZE * (i - 1)], B_SIZE);
		i++;
	}
	if (red != 20)
		error;
	return (buff);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*file;
	char	**list;

	if (argc != 2)
	{
		write(1, "usage: ./fillit file_name\n", 26);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	file = get(fd, 2);
	list = create_list(file, 0);
	proceed(file, list);
}

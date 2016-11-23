/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:15:17 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/23 12:02:41 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "stdio.h"

void	check_bad(char *tet, int i)
{
	int		count;

	count = 0;
	while (VALID(tet[i]))
	{
		if (tet[i] == '#')
			count++;
		i++;
	}
	if (i != 16 || count != 4)
		error();
}

void	xposition(char *tet, int i)
{
	while (tet[0] == '.' && tet[4] == '.' && tet[8] == '.' && tet[12] == '.')
	{
		while(i < 15)
		{
			tet[i] = tet[i + 1];
			i++;
		}
		tet[i] = '.';
		i = 0;
	}
}

void	position(char *tet, char fill, int i, int count)
{
	check_bad(tet, 0);
	while (count == 0)
	{
		while (i < 4)
			count = tet[i++] == '#' ? count + 1 : count;
		if (count == 0)
		{
			while (i < 16)
			{
				tet[i - 4] = tet[i];
				i++;
			}
			while (i > 11)
				tet[i--] = '.';
		}
		i = 0;
	}
	xposition(tet, 0);
	i = 0;
	while (i < 16)
	{
		tet[i] = tet[i] == '#' ? fill : tet[i];
		i++;
	}
}

void	parse(char *file, char **list, int num, int i)
{
	int		y;
	int		x;
	int		temp;
	char	fill;

	fill = 'A';
	y = 0;
	while (y < num)
	{
		x = 0;
		while (x < 16)
		{
			temp = i;
			while (i < temp + 4)
				list[y][x++] = file[i++];
			if (file[i++] != '\n')
				error();
		}
		list[y][16] = '\0';
		position(list[y], fill, 0, 0);
		printf("%i:\n%s\n\n", y + 1, list[y]);
		fill++;
		y++;
		i++;
	}
}

void	proceed(char *file, char **list, int num)
{
	parse(file, list, num, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 19:41:50 by mwooden           #+#    #+#             */
/*   Updated: 2016/11/23 11:31:49 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define B_SIZE 21
# define VALID(x) (x == '#' || x == '.')

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void	error();

void	proceed(char *file, char **list, int num);

#endif

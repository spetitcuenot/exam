/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   brainfuckc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/05 10:06:20 by exam         #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 13:00:15 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 2048

int main(int ac, char **av)
{
	char		*brain;
	int			i;
	int			j;
	int 		search;

	i = 0;
	j = 0;
	if (ac == 2)
	{
		if (!(brain = (char*)malloc(sizeof(brain) * BUFF_SIZE + 1)))
			return (0);
		while (i++ <= BUFF_SIZE)
			brain[j++] = '\0';
		j = 0;
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] == '>')
				j++;
			else if (av[1][i] == '<')
				j--;
			else if (av[1][i] == '+')
				brain[j] += 1;
			else if (av[1][i] == '-')
				brain[j] -= 1;
			if (av[1][i] == '.')
				write(1, &brain[j], 1);
			if (av[1][i] == '[' && brain[j] == 0)
			{
				search = 1;
				while (search)
				{
					i++;
					av[1][i] == '[' ? search += 1 : search;
					av[1][i] == ']' ? search -= 1 : search;
				}
			}
			if (av[1][i] == ']' && brain[j] != 0)
			{
				search = 1;
				while (search)
				{
					i--;
					av[1][i] == '[' ? search -= 1 : search;
					av[1][i] == ']' ? search += 1 : search;
				}
			}
			i++;	
		}
	}
	else
		write(1, "\n", 1);	
	return (0);
}
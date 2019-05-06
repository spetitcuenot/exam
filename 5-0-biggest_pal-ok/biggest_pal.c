/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   biggest_pal.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: exam <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 10:10:16 by exam         #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 11:58:41 by exam        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int check_pal(char *str, int a, int b)
{
	while(str && a < b)
	{
		if (str[a++] != str[b--])
			return (0);
	}
	return (1);
}
int check_same(char *str)
{
	int  i;
	char p;

	i = 0;
	p = str[0];
	while (str[i])
	{
		if (str[i] != p)
			return (0);
	i++;
	}
	return (1);
}
int main(int ac, char **av)
{
	int i;
	int j;
	int biggest;
	int spal;
	int epal;
	int len;

	i = 0;
	j = 0;
	biggest = 0;
	spal = 0;
	epal = 0;
	len = 0;

	if (ac == 2)
	{
		while (av[1][i++] != '\0')
			len++;
		j = len - 1;
		if (len == 1)
		{
			av[1][1] = '\n';
			return (write(1, &av[1][0], 2));
		}
		if (len > 10000 && check_same(av[1]) == 1)
		{
			av[1][len] = '\n';
			return (write(1, &av[1][0], len + 1));
		}
		i = 0;
		while (i < j)
		{
			if (av[1][i] == av[1][j])
			{
				if (check_pal(av[1], i, j) == 1)
				{
					if (biggest < j - i)
					{
						biggest = j - i;
						spal = i;
						epal = j;
					}
				}
			}
			if (i + 1 == j)
			{
				j--;
				i = -1;
			}
		i++;
		}
		
		if (biggest > 0)
		{
			av[1][epal + 1] = '\n';
			return (write(1, &av[1][spal], biggest + 2));
		}
		else
			return (write(1, "\n", 1));
	}
	else
		return (write(1, "\n", 1));
}

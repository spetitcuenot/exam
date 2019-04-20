/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   biggest_pal.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 10:02:52 by exam         #+#   ##    ##    #+#       */
/*   Updated: 2019/04/20 16:55:42 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int check_pal(char *str, int a, int b)
{
	while (a <= b)
	{	
		if (str[a++] != str[b--])
			return (0);
	}
	return (1);
}
int 	same_char(char *str)
{
	int i;
	char c;

	i = 0;
	c = str[0];
	while (str[i] == c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}



int main (int ac, char **av)
{
	int i;
	int j;
	int l;
	int len;
	int bigest;
	int ipal;
	int epal;
	int n;

	i = 0;
	j = 0;
	l = 0;
	len = 0;
	bigest = 0;
	ipal = 0;
	epal = 0;
	n = 0;
	if (ac == 2)
	{
			while (av[1][i++] != '\0')
				len++;
			j = len - 1;
			i = 0;
			if (len == 1)
			{
				av[1][i + 1] = '\n';
				return (write(1, &av[1][i], 2));
			}
			i = 0;
            if (same_char(av[1]) == 1)
            {
                av[1][len] = '\n';
                return (write(1, &av[1][i], len + 1));
            }
    		while (i < j)
			{
				if (av[1][i] == av[1][j])
				{
					if (check_pal(av[1], i, j) == 1)
					{
						if (bigest < j - i + 1)
						{
							bigest = j - i + 1;
							ipal = i;
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
			if (bigest > 0)
			{
				av[1][epal + 1] = '\n';
				return (write(1, &av[1][ipal], bigest + 1));
			}
			else
				return (write(1, "\n", 1));
	}
	else
		return (write(1, "\n", 1));
	return (0);
}
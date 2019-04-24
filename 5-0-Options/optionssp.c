/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   optionssp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 16:03:04 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 22:58:07 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int scanarg(char *str)
{
	int i;
	i = 0;
	while (str[i++])
	{	
		printf("while str[i]%s\n", &str[i]);
		if (str[i] <= 97 || str[i] >= 122)
			return (0);
		else 
			return (1);
	}
	return (0);
}
int scanoption(char *str)
{
	printf("str[0]:%s\n", &str[0]);
	if (str[0] != '-')
		return (0);
	else
		return (1);
}

int main(int ac, char **av)
{
	int i;
	int j;
	int c;
	int l;
	char *strref = "zyxwvutsrqponmlkjihgfedcba";

	i = 1;
	j = 1;
	c = 0;
	l = 0;
	
	if (ac < 2)
		return (write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36));
	else
		while (i < ac)
		{
			if (scanoption(av[i]) == 1 && av[i][1] == 'h')
				return (write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36));
		i++;
		}
		i = 1;
		while (i < ac)
		{
			if (scanarg(av[i]) == 1 && scanoption(av[i]) == 1)
				return (write(1, "Invalid Option\n", 15));
		i++;
		}
		i = 1;
		while (c < 35)
		{
			while (strref[l])
			{
				if (c == 8 || c == 17 || c == 26)
					{
						write (1, " ", 1);
						c++;
					}
				while (c++ < 6)
					write (1, "0", 1);
				while (i < ac)
				{
					while (av[i][j] != '\0')
					{
						if (av[i][j] == strref[l])
						{
							write(1, "1", 1);
							c++;
						}
						else 
							write(1, "0", 1);
					j++;
					}
				i++;	
				}
			l++;
			}
		c++;
		}				
					
	return (0);
}
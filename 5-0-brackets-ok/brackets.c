/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   brackets.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: exam <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 10:10:15 by exam         #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 11:39:30 by exam        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int checkb(char a, char b)
{
	if ((a == '(' && b == ')') || (a == '{' && b == '}') 
			|| (a == '[' && b == ']'))
		return (1);
	else
		return (0);
}

int brackets(char *s)
{
	int i;
	char t[4096];
	int op;

	i = 0;
	op = 0;
	while (s[i])
	{
		if (s[i] && (s[i] == '(' || s[i] == '[' || s[i] == '{'))
			t[++op] = s[i];
		if ((s[i]) && (s[i] == ')' || s[i] == ']' || s[i] == '}') 
				&& !checkb(t[op--], s[i]))
			return (0);
	i++;
	}
	return (!op);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (brackets(av[i]) == 1)
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
		i++;
		}
	}
	else
		return (write(1, "\n", 1));
	return (0);
}


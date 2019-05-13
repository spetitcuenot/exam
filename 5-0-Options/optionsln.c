/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   optionsln.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/12 10:05:01 by exam         #+#   ##    ##    #+#       */
/*   Updated: 2019/05/13 19:09:17 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include	<unistd.h>

int		checkopen (char *str)
{
	int i;
	int b;

	i = 0;
	b = 0;
	if (str[0] == '-')
		i++;
	  
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <='z')
			b = 1;
		else
			return (0);
		i++;
	}
		
	if (b == 1)
		return(1);
	return (0);
}


int		main(int ac, char **av)
{
	int i;
	int j;
	int k;
	int l;
	int b;
	char *alpha = "zyxwvutsrqponmlkjihgfedcba";

	i = 1;
	j = 0;
	k = 1;
	l = 0;
	b = 0;
	
	if (ac >= 2)
	{
		while (i < ac && k == 1)
					(checkopen(av[i++]) == 0) ? (k = 0) : (k = 1);
		if (k == 1)
		{
			i = 1;
			k = 0;
			j = 0;
			while (i < ac)
			{
				if (av[i][1] == 'h' && av[i][1] != '\0')
					return (write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36));
			i++;
			}
			i = 1;
			while (k < 6)
			{
					write (1, "0", 1);
					k++;
			}
			while (k < 35)
			{
				while (alpha[j] != '\0')
				{
					while ( i < ac)
					{
						if (k == 8 || k == 17 || k == 26)
							{
								write (1, " ", 1);
								k++;
							}
							while (av[i][l] != '\0' && j < 26)
							{
								if ( k == 8 || k == 17 || k == 26)
								{
									write (1, " ", 1);
									k++;
								}
								if (alpha[j] == av[i][l])
								{
									write (1, "1", 1);
									j++;
									k++;
									i = 1;
									l = 0;
									b = 1;
								}
								else
									l++;
							}
							i++;
							if ( i == ac && b == 0 && k < 35)
							{
								write (1, "0", 1);
								k++;
								j++;
							}
							if (i == ac && j < 26)
								i = 1;
							b = 0;
							l = 0;
					}			
				}
				write(1, "\n", 1);
			}	
		}
		else
			write (1, "Invalid Option\n", 15);
	}
	else
		write (1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
}
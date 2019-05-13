/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   optionssp2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/13 10:54:08 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/13 18:23:44 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int checkoption(char *str)
{
	int i;
	int op;
   //	int opv;	

	i = 0;
	op = 0;
	//opv = 0;
	/*(str[0] == '-') ? (op = 0) : (op = 1);
	i++;
	while (str)
	{
		(str[i] < 'a' && str[i] > 'z') 	? (op++) : (op = 0);
	i++;
	}*/
	if (str[0] == '-')
		i++;
	printf("op : %d\n", op);
	while (str[i] != '\0')
	{
		printf("W op :%d, str[i] : %c\n", op, str[i]);
		if (str[i] >= 'a' && str[i] <= 'z')
			op = 1;
		else 
			return (0);
	i++;
	}
	if (op == 1)
		return (1);
	return (0);

	printf("op final : %d\n", op);
}

int main (int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	printf("ac : %d", ac);
	if (ac >= 2)
	{
		while (i < ac && )
		{   
			printf("While\n");
			if (checkoption(av[i]) == 0)
				return (write(1, "Invalid Option\n", 15));
			else
			{
				i = 0;
				while (av[i] != '\0')
				{
					if (av[i][1] == 'h' && av[i][1] !='\0')
						return (write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36));
				i++;
				}
				i = 0;
				while (i++ < 6)
				{
					write(1, "0", 1);
				}
			}
		i++;
		}
		
				
			
	}
	else 
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	return (0);
}

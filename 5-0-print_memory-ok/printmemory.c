/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printmemory.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/30 08:29:52 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 09:49:16 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void print_memory(const void *addr, size_t size)
{
	size_t i;
	size_t j;
	unsigned char *p;
	char *str;

	i = 0;
	str = "0123456789abcdef";
	p = (unsigned char *)addr;
	while (i < size)
	{
			j = 0;
			while (j < 16 && i + j < size)
			{
				write(1, &str[(*(p + i + j)/ 16) % 16], 1);
				write(1, &str[*(p + i + i) % 16], 1);
				if (j % 2)
					write(1, " ", 1);
				j++;
			}
			while (j < 16)
			{
				write(1, "  ", 2);
				if (j % 2)
					write(1, " ", 1);
				j++;
			}
			j = 0;
			while (j < 16 && i + j < size)
			{
				if (*(p + i + j) >= 32 && *(p + i + j) < 127)
					write(1, p + i + j, 1);
				else 
					write(1, ".", 1);
				j++;
			}
			write(1, "\n", 1);
			i +=16;
	}
}
int	main(void)
{
		int	tab[16] = {0, 23, 150, 255,
				              12, 16,  42, 103};

			print_memory(tab, sizeof(tab));
				return (0);
}

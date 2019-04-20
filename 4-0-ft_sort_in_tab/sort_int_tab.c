/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_int_tab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 11:46:42 by exam         #+#   ##    ##    #+#       */
/*   Updated: 2019/04/20 16:45:08 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int tmp;

	i = 0;
	tmp = 0;

	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				sort_int_tab(tab, size);
			}
	i++;
	}
}
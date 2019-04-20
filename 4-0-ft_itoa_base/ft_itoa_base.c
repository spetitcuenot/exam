/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 11:53:42 by exam         #+#   ##    ##    #+#       */
/*   Updated: 2019/04/20 16:38:13 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa_base(int value, int base)
{
	int 	len;
	char	strbase[] = {"0123456789ABCDEF"};
	int		tmp;
	char	*conv;

	tmp = value;
	len = 0;
	if (base < 2 || base > 16)
		return (0);
	while (tmp)
	{
		tmp /= base;
		len++;
	}
	tmp = value;
	if (tmp < 0)
	{
		if (base == 10)
			len++;
		tmp *= -1;
	}
	if (!(conv = (char *)malloc(sizeof((char) len + 1))))
		return (0);
	if (value == 0)
	{
		conv = "0";
		return (conv);
	}
	if (value == -2147483648 && base == 10)
		return ("-2147483648");
	conv[len] = '\0';
	while (tmp)
	{
		conv[--len] = strbase[tmp % base];
		tmp /= base;
	}
	if (value < 0 && base == 10)
		conv[0] = '-';
	return (conv);
}

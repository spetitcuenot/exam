/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   brackets.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 17:40:49 by exam         #+#   ##    ##    #+#       */
/*   Updated: 2019/04/22 15:51:15 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int     check_brackets(a, b)
{
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
        return (1);
    return (0);
}
int     brackets(char *s)
{
    int     i;
    int     op;
    char    t[4096];
    i = 0;
    op = 0;
    while (s[i])
    {
        if (s[i] && (s[i] == '(' || s[i] == '[' || s[i] == '{'))
            t[++op] = s[i];
        if (s[i] && (s[i] == ')' || s[i] == ']' || s[i] == '}') &&
                !(check_brackets(t[op--], s[i])))
            return (0);
        i++;
    } 
    
    return (!op); 
}
int     main(int ac , char **av)
{
    int     i;
    i = 1;
    if (ac > 1)
    {
        while(i < ac)
        {
            if (brackets(av[i]) == 1)
                write (1, "OK\n", 3);
            else
                write(1, "Error\n", 6);
            i++;
        }
    }
    else
        write(1, "\n", 1); 
    return (0);
}
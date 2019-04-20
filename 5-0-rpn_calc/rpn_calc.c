/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rpn_calc.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 14:59:21 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/20 17:40:31 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int checknpiok(char *str)  //inutile a integer dans la recursive 
{
    int i;
    int nbop;
    int nbdigit;

    i = 0;
    nbop = 0;
    nbdigit = 0;
    while (str[i])
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '+' || str[i] == '/' || str[i] == '*' || str[i] == '-' ||str[i] == '%'))
            return (0);
        if (str[i] >= '0' && str[i] <= '9')
            nbdigit++;
        if (str[i] == '+' || str[i] == '/' || str[i] == '*' || str[i] == '-' ||str[i] == '%')
            nbop++;  
    i++;
    }
    printf("nbdigit : %d, nbop : %d\n", nbdigit, nbop);
    if (nbdigit == nbop + 1)
        return (1);
    else 
        return (0);
}


int calcul(int d1, int d2, char op)
{
    if (op == '+')
        return (d2 + d1);
    if (op == '-')
        return (d2 - d1);   
    if (op == '*')
        return (d2 * d1);   
    if (op == '/')
        return (d2 / d1);   
    return (d2 % d1);  
}
    

void searchop(char *str)
    {
        int i = -1;
        int j = -1;
        int tmpd1 = 0;
        int tmpd2 = 0;
        while (str[++i] && j < 0)
            if (str[i] == '+' || str[i] == '/' || str[i] == '*' || str[i] == '-' ||str[i] == '%')
                j = i;
        j--;
        while (str[j] == ' ') //faire une fonction
            j--;
        while (j >= 0 && str[j] != ' ') //faire une fonction des 2
            j--;

        /*if (j < 0)
        {   
            if () // chercher le character ou nombre unique si oui le printer si non error
            printf("Error\n");
            return ;
        }*/
        tmpd1 = atoi(str + j + 1);
        while (str[j] == ' ')
            j--;
        
        while (j >= 0 && str[j] != ' ')  
            j--;
        tmpd2 = atoi(str + j + 1);

        if (!tmpd1 && (str[i - 1] == '/' || str[i - 1] == '%' ))
        {   
            printf("Error\n");
            return ;
        }
        printf("%d\n", (tmpd1 = calcul(tmpd1, tmpd2, str[i - 1])));
        while (++j < i)
            str[j] = ' ';
        if (!tmpd1)
            str[j - 1] = '0';
        while (tmpd1)
            {
                str[--j] = tmpd1 % 10 + '0';
                tmpd1 /= 10;
            }
        printf("str :%s\n", str);
        searchop(str);
    }


int main (int ac, char **av)
{
    int i;
    int len;



    i = 0;
    len = 0;
    if (ac == 2)
    {
        while (av[1][i++])
            len++;
        printf("len : %d\n", len);
        //if (checknpiok(av[1]) == 1)
        //{
            printf("Lancement du calcul\n");
        searchop(av[1]);
        /*else
            return (write(1, "Error\n", 6));*/
    }
    else 
        return (write(1, "Error\n", 6));
    return (0);
}
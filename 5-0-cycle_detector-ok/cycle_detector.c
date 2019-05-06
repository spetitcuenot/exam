/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cycle_detector.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: spetitcu <spetitcu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 08:38:05 by spetitcu     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/06 16:10:57 by spetitcu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>   // <--
#include <stdio.h>
//#include "list.h" <--

typedef struct     s_list 
{
    int            data;
    struct s_list  *next;
}                  t_list;

int        cycle_detector(const t_list *list)
 {
    const t_list  *elemslow;
    const t_list  *elemfast;
        
    elemslow = list;
    elemfast = list;
    while (elemslow && elemslow->next)
    {
        if (elemfast->next != NULL && elemfast->next->next != NULL)
            elemfast = elemfast->next->next;
        else
            return (0);
        if (elemslow == elemfast)
            return (1);
        if (elemslow->next != NULL)
            elemslow = elemslow->next;
    }
    return (0);
 }

 int main (void)
 {  
     t_list *elem, *elem2, *elem3, *elem4,
            *elem5;
             //*elem6;

    elem = malloc(sizeof(t_list));
    elem2 = malloc(sizeof(t_list));
    elem3 = malloc(sizeof(t_list));
    elem4 = malloc(sizeof(t_list));
    elem5 = malloc(sizeof(t_list));
    //elem6 = malloc(sizeof(t_list));

    elem->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;
    elem4->next = elem5;
    elem5->next = NULL;
    //elem6->next = NULL;

    printf("Retour :%d\n", cycle_detector(elem));

    return (0);
 }
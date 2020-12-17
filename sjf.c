#include <stdio.h>
#include <stdlib.h>
#include "sjf.h"

int short_process(Process **tab , int size , int ct)
{
    int i , min_bt  = 100000 , i_min = -1 ;

    for( i = 0 ; i < size ; i++)
	if(tab[i]->status != EXECUTER && tab[i]->AT <= ct && tab[i]->BT < min_bt)
	{
	    min_bt = tab[i]->BT ;
	    i_min = i ;
	}
    return i_min ;

}

int search_ct(Process **tab , int size)
{
    int i , ct = tab[0]->AT ;

    for(i = 1 ; i < size ; i++)
	if(tab[i]->AT < ct)
	    ct = tab[i]->AT ;
    return ct ;
}

void sjf(Process **tab , int size)
{
    int i , ct = search_ct(tab , size) , i_sp ;

    do
    {
	i_sp = short_process(tab , size , ct) ;
	if(i_sp == -1)
	    break ;

	for(i = 0 ; i < size ; i++)
	    if(i != i_sp && tab[i]->status != EXECUTER && ct >= tab[i]->AT)
		tab[i]->WT+=tab[i_sp]->BT ;
	
	ct+=tab[i_sp]->BT ;
	tab[i_sp]->CT = ct ;
	tab[i_sp]->TAT = tab[i_sp]->CT - tab[i_sp]->AT ;
	tab[i_sp]->RT = tab[i_sp]->WT ;
	tab[i_sp]->status = EXECUTER ;

	tab[i_sp]->RT = ct - tab[i_sp]->AT ;

	printf("\t\t P%d ", tab[i_sp]->id) ;
	
    }while(ct) ;
}

#include <stdio.h>
#include <stdlib.h>
#include "sjf.h"

    
int main(int c , char **arg)
{
    int x , i ;
    Process **tab = NULL ;

    if( c == 2 )
    {
	tab = malloc(sizeof(Process*)) ;
	x = atoi(arg[1]);
	    
	if(tab != NULL)
	{
	    tab[0] = malloc(sizeof(Process)*x) ;
	    for(i = 0 ; i < x ; i++)
		tab[i] = scan_process(i+1) ;
	    
	    sjf(tab , x) ;
	    print(tab , x) ;
	    free_process(tab , x);
	}
    }

    else
	printf("\n Usage : préciser le nombre de processus en argument lors de l'execution \n\n") ;

    return 0 ;	    
}

#ifndef SJF

#define SJF
#define EXECUTER 1
#define NOT_EXECUTER 0

typedef struct
{
    int id ;
    int AT ;
    int BT ;
    int CT ;
    int TAT ;
    int WT ;
    int RT ;
    int status ;
}Process ;


int short_process(Process **tab , int size , int ct) ;

int search_ct(Process **tab , int size) ;

void sjf(Process **tab , int size) ;

void free_process(Process **tab , int size) ;

void print(Process **tab, int size) ;

Process * scan_process(int id) ;

#endif

#include "functions.h"

int identify( char key ,char row_1[] ,char row_2[] ,char row_3[], int *row_number){
    int j;

    j = search_row(key,row_1);
        *row_number=1;

    if(j == 11){
        j=search_row(key,row_2);
        *row_number=2;
    }

    if(j == 11){
       j = search_row(key,row_3);
       *row_number=3;
       }

    return j;

}
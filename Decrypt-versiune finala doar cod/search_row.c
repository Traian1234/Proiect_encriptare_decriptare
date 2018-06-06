#include "functions.h"

int search_row(char key,char row[11]){
     int i;

     if (key==' '){
        return 12;

     }
     for(i=0;i<strlen(row);i++){
        if (key == row[i]){
            return i;
        }
     }

     return 11 ;
}
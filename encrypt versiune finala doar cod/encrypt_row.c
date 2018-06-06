#include "functions.h"

void encrypt_row(char row[], int position){
        int i;
        int aux;
        int j;
        char cpy[12];

        strcpy(cpy,row);

        aux = position;

            for(i = 0 ; i < strlen(row) - position; i++){
                row[i] = cpy[aux];
                aux++;
            }

            j = 0;

            for(i = strlen(row) - position; i < strlen(row); i++){
                row[i] = cpy[j];
                j++;
            }

            row[i + 1] = cpy[0];
        }
 
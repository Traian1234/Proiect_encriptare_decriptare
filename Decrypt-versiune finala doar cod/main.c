#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "functions.h"

int main()
{
    char message[100];
    char row_1[12] = "qwertyuiop";
    char row_2[11] = "asdfghjkl";
    char row_3[9] = "zxcvbnm";
    char key;

    int i ;
    int position;
    int message_id[100];
    int row_number[100];


    printf("introdu mesajul :");
    gets(message);
    if(message[0] != ' ' && message[1]==' '){
        key = message[0];
    }else{
        printf("Prima litera din mesaj trebuie urmata de un spatiu");
		system("pause");
        return 0;
    }

    position = identify(key ,row_1 ,row_2 ,row_3 ,&row_number[0]);

    for(i = 0; i < strlen(message) ; i++){
        message_id[i] = identify(message[i],row_1,row_2,row_3,&row_number[i]);
        if(message_id[i] != 12){
            message_id[i]=message_id[i]-position;
            if(message_id[i] < 0){
                if(row_number[i]==1){
                    message_id[i] = message_id[i] + 10;
                }

                if(row_number[i]==2){
                    message_id[i] = message_id[i] + 9;
                }

                if(row_number[i]==3){
                    message_id[i] = message_id[i] + 7;
                }

            }
        }
    }


    print_decrypted(message,row_1,row_2,row_3,message_id,row_number,position);
	printf("mesajul decryptat este :");
	printf("%s",message);

	printf("\n");
	system("pause");
    return 0;
}
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
        printf("Prima litera din mesaj trebuie urmata de un spatiu\ns");
		system("pause");
        return 0;
    }

    position = identify(key ,row_1 ,row_2 ,row_3 ,&row_number[0]);

    for(i = 0; i < strlen(message) ; i++){
        message_id[i] = identify(message[i],row_1,row_2,row_3,&row_number[i]);
    }

    if(position==8){
        strcpy(row_1,"opqwertyui");
        strcpy(row_2,"lasdfghjk");
        strcpy(row_3,"xcvbnmz");

    }else{
    encrypt_row(row_1,position);
    encrypt_row(row_2,position);
    encrypt_row(row_3,position);
	}


    print_encrypted(message,row_1,row_2,row_3,message_id,row_number);
	printf("Mesajul encryptat este :");
    printf("%s",message);
	printf("\n");
	system("pause");

    return 0;
}

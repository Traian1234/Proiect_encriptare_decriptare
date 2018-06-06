#include "functions.h"

void print_decrypted(char message[] ,char row_1[] ,char row_2[] ,char row_3[] ,int message_id[] ,int row_number[],int position){
    int i;
    for(i = 0; i < strlen(message); i++){
        if (message_id[i] == 12){
            message[i] = ' ';
            row_number[i] = 0;
            continue;
        }

        if(row_number[i] == 1){
            message[i] = row_1[message_id[i]];
            continue;
        }

        if(row_number[i] == 2){
            message[i] = row_2[message_id[i]];
            continue;
        }

        if(row_number[i] == 3){
			if(position == 8 && message[i]=='z'){
				message[i]='m';
				continue;
			}
            message[i] = row_3[message_id[i]];
            continue;
        }
    }
}

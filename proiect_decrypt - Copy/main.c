#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

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


void print_encrypted(char message[] ,char row_1[] ,char row_2[] ,char row_3[] ,int message_id[] ,int row_number[]){
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
            message[i] = row_3[message_id[i]];
            continue;
        }
    }
}

void find_message_id(int *message_id,int position , int row_number){

    message_id = message_id - position;
        if(message_id < 0){
            if(row_number == 1){
                *message_id = *message_id + 10;
            }

            if(row_number == 2){
                *message_id = *message_id + 9;
            }

            if(row_number == 3){
                *message_id = *message_id + 7;
            }
        }
}


int main()
{
    char message[100];
    char row_1[12] = "qwertyuiop";
    char row_2[11] = "asdfghjkl";
    char row_3[9] = "zxcvbnm";
    char key;
    char ch;

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
        return 0;
    }

    position = identify(key ,row_1 ,row_2 ,row_3 ,&row_number[0]);

    for(i = 0; i < strlen(message) ; i++){
        message_id[i] = identify(message[i],row_1,row_2,row_3,&row_number[i]);
        if(message_id[i] != 12){
            find_message_id(&message_id[i],position,row_number);
        }
    }


    print_encrypted(message,row_1,row_2,row_3,message_id,row_number);

    printf("%s",message);

    return 0;
}

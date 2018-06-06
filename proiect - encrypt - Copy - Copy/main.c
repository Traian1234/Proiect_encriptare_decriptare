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

    void encrypt_row(char row[], int position){
        int i;
        int aux;
        int j;
        char cpy[12];

        strcpy(cpy,row);

        aux = position;

        if(position == 8){
            for(i = 1 ; i < strlen(row)-1; i++){
                row[i-1]=cpy[i];
            }
            row[i]=cpy[0];
            row[i-1]=cpy[strlen(row)-1];


        }else{
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
            message[i] = row_2[message_id[i] ];
            continue;
        }

        if(row_number[i] == 3){
            message[i] = row_3[message_id[i]];
            continue;
        }
    }
}



int main()
{
    FILE *fp;
    fp=fopen("encrypted_message.txt","w");

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
    encrypt_row(row_3,position);}

    printf("\n%s",row_1);
    printf("\n%s",row_2);
    printf("\n%s",row_3);

    print_encrypted(message,row_1,row_2,row_3,message_id,row_number);
    fputs(message,fp);
    printf("%s",message);



    return 0;
}

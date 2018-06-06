#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

 int search_row(char key,char row[],int n){
     int i;
     int k;
     k=0;
     for(i=0;i<n;i++){
        if (key == row[i]){
            return i;
        }
     }

     return 11 ;
}

int encrypt(row){


}

int main()
{
    char message[100];
    char row_1[10]={'q','w','e','r','t','y','u','i','o','p'};
    char row_2[9]={'a','s','d','f','g','h','j','k','l'};
    char row_3[7]={'z','x','c','v','b','n','m'};
    char key;
    char ch;

    int i ;
    int i_1=10;
    int i_2=9;
    int i_3=7;

    printf("introdu mesajul :");
    gets(message);
    key=message[0];

    i=search_row(key,row_1,i_1);

    if(i==11){
        i=search_row(key,row_2,i_2);
    }
    if(i==11){
       i=search_row(key,row_3,i_3);
       }




    printf("%d",i);



    return 0;
}

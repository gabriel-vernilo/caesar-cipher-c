#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
ABCDEFGHIJKLMNOPQRSTUVWXYZ
DEFGHIJKLMNOPQRSTUVWXYZABC
*/


void main(){
int res,shift,index,new_index;
char text[51];
char *find_index;
char alfa[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

printf("TYPE:\n[1]TO ENCODE\n[2]TO DECODE\n: ");
fflush(stdin);
scanf("%d",&res);
    if((res == 1) || (res == 2)){
        printf("type the shift: ");
        fflush(stdin);
        scanf("%d",&shift);
    }
    if(res == 1){
        printf("text to encode: ");
        fflush(stdin);
        fgets(text,49,stdin);
        for(int x = 0; x<(strlen(text)-1); x++){
            if(text[x]==' ') {}
            else{
                find_index = strchr(alfa,text[x]);
                index = (int) (find_index - alfa);
                if((index + shift) > 25){
                    new_index = (26 - shift) - index ;
                    if(new_index < 0){
                        new_index = new_index * -1;
                    }
                    text[x] = alfa[new_index];
                }
                else{
                    new_index = index + shift;
                    text[x] = alfa[new_index];
                }
            }
            printf("%c",text[x]);
        }
    }
    else if (res == 2){
        printf("text to decode: ");
        fflush(stdin);
        fgets(text,49,stdin);
        for(int x = 0; x<(strlen(text)-1); x++){
            if(text[x] == ' '){}
            else{
                find_index = strchr(alfa,text[x]);
                index = (int) (find_index - alfa);
                if(index < shift){
                    new_index = (26 - shift + index);
                    text[x] = alfa[new_index];
                }
                else{
                    new_index = index - shift;
                    text[x]=alfa[new_index];
                }
            }
            printf("%c",text[x]);
        }
    }
    /*else if(res ==3){
    printf("text to bruteforce decode: ");
    fflush(stdin);
    fgets(text,49,stdin);
    shift = 0;
    while(shift <26){
        printf("Shift %d :  ",shift);
        for(int i=0;i<(strlen(text)-1);i++){
            if(text[i]== ' '){}
            else{
                find_index = strchr(alfa,text[i]);
                index = (int) (find_index - alfa);
                if(index<shift){
                    new_index = (26 - shift +index);
                    text[i] = alfa[new_index];
                }
                else{
                    new_index = index - shift;
                    text[i] = alfa[new_index];
                }
            }
            printf("%c",text[i]);
        }
    printf("\n");
    shift++;
    }


    }*/
    else{
        printf("type a valid option\n");
        main();
    }
printf("\n");
system("pause");
return;
}

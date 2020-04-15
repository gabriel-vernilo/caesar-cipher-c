#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
ABCDEFGHIJKLMNOPQRSTUVWXYZ
DEFGHIJKLMNOPQRSTUVWXYZABC
*/


void main(){
int res;
char text[50];

printf("TYPE:\n[1]TO ENCODE\n[2]TO DECODE\n: ");
fflush(stdin);
scanf("%d",&res);

    if(res == 1){
        printf("text to encode: ");
        fflush(stdin);
        fgets(text,49,stdin);
        for(int x = 0; x<strlen(text); x++){
            if(text[x]=='x') {
            text[x] = 'a';}
            else if(text[x]=='y'){
            text[x] = 'b';}
            else if(text[x]=='z'){
            text[x] = 'c';}
            else if(text[x] == ' '){}
            else{(text[x]+=3);}
            printf("%c",text[x]);
        }
    }
    else if (res == 2){
        printf("text to decode: ");
        fflush(stdin);
        fgets(text,49,stdin);
        for(int x = 0; x<strlen(text); x++){
            if(text[x]=='a') {
            text[x] = 'x';}
            else if(text[x]=='b'){
            text[x] = 'y';}
            else if(text[x]=='c'){
            text[x] = 'z';}
            else if(text[x] == ' '){}
            else{(text[x]-=3);}
            printf("%c",text[x]);
        }
    }
    else{
        printf("type a valid option");
        main();
    }
printf("\n");
system("pause");
return;
}

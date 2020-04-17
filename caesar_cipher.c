#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encode(char text_to_cript[], int shift);
int decode(char text_to_decrip[], int shift);
int bruteforce(char text_to_decrip[]);
char text[51],text_encoded[51],text_decoded[51];
char alfabeto[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int shift;
int choice;

int main(int argc, char *argv[]){
printf("TYPE:\n[1]TO DECODE\nOR\n[2]TO ENCODE\n[3]TO BRUTEFORCE DECODE\n : ");
fflush(stdin);
scanf("%d",&choice);
printf("type the text: ");
fflush(stdin);
fgets(text,49,stdin);

if(choice == 1){
    if(argv[1!=0]){
        shift = atoi(argv[1]);
    }
    else{
        printf("type the shift: ");
        fflush(stdin);
        scanf("%d",&shift);
    }
    text_decoded[49] = decode(text,shift);
}
else if (choice == 2){
    if(argv[1!=0]){
        shift = atoi(argv[1]);
    }
    else{
        printf("type the shift: ");
        fflush(stdin);
        scanf("%d",&shift);
    }
    text_encoded[49] = encode(text,shift);
}

else if(choice == 3){
    bruteforce(text);
}

else{
    printf("\n TYPE A VALID OPTION \n");
}

printf("\n");
system("pause");
return 0;
}


int bruteforce(char text[50]){

for(int bf=0;bf<26;bf++){
    printf("shift %d : ",bf);
    int new_index,index;
    new_index=index=0;
    for(int i=0;i<(strlen(text)-1);i++){
        if(text[i]!=' '){
            char *find_index = strchr(alfabeto, text[i]);
            int index = (int) (find_index - alfabeto);
            if(index<bf){
                new_index = 26-bf + index;
            }
            else{
                new_index = index - bf;
            }
            printf("%c",alfabeto[new_index]);
        }
        else{
            printf(" ");
        }
    }
    printf("\n");
}
return 0;
}

int decode(char text[50],int shift){
printf("Decoded text: ");
for(int i=0;i<(strlen(text)-1);i++){
    if(text[i]!=' '){
        char *find_index = strchr(alfabeto, text[i]);
        int index = (int) (find_index - alfabeto);
        int new_index;
        if(index<shift){
            new_index = 26-shift + index;
        }
        else{
            new_index = index - shift;
        }
        text[i] = alfabeto[new_index];
        printf("%c",text[i]);
    }
    else{
        printf(" ");
    }
}
return 0;
}

int encode(char text_to_cript[50], int shift){
printf("Encoded text: ");
for(int i=0; i<(strlen(text_to_cript)-1);i++){
    if (text_to_cript[i] != ' '){
        char *find_index = strchr(alfabeto, text_to_cript[i]);
        int index = (int) (find_index - alfabeto);
        int new_index;
        if((index+shift)>25){
            new_index = (26 - shift) - index;
            if(new_index<0){
                new_index *=-1;
            }
        }
        else{
            new_index = index + shift;
        }
        text_to_cript[i] = alfabeto[new_index];
        printf("%c", text_to_cript[i]);
    }
    else{
        printf(" ");
    }
}

return 0;
}

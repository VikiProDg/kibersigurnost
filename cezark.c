#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000

char* cezar_cipher(char*str, int key){
    int length= strlen(str);
    char*cipher =(char*) malloc(sizeof(char)* (length+1));

    for(int i= 0; i < length; i++){
        if(str[i] >='a' && str[i] <='z'){
            cipher[i] = ((str[i] -'a' + key) %26)+ 'a';

        }else if(str[i] >='A' && str[i] <='Z'){
            cipher[i] = ((str[i] -'A' + key) %26)+ 'A';
    }else{
        cipher[i]= str[i];
    }
    }
    cipher[length] = '\0';
    return cipher;
}
int main(){
    FILE *cesar= fopen("cesar.txt","w");
    char str[MAXN];
    fgets(str, MAXN, stdin);
    str[strcspn(str, "\n")]=0;

    int key;
    scanf("%d",&key);
    char *cipher= cezar_cipher(str,key);
    fprintf(cesar, "%s", cipher);
    free(cipher);
    fclose(cesar);
    return EXIT_SUCCESS;

}

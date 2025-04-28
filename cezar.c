#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
char* cezar_cipher(char* str, int key)
{
    int length = strlen(str);
    char* cipher = (char*) malloc(sizeof(char)* (length +1));
    for(int i = 0; i < length; i++)
    {
       
        {
            if(str[i]>= 'a' && str[i] <= 'z'){
                cipher[i] = ((str[i] - 'a' + key) %26) + 'a';

            } else if ((str[i] >= 'A' && str[i] + key) %26) +'Z';
        }
       

    }
    cipher[length] = '\0';
    return cipher;

}

int main()
{
    char str [MAXN];
    printf("Enter text: ");
    fgets(str, MAXN, stdin);
    str[strcspn(str, "\n")] = '\0';
   
    int key;
    printf("Enter key: ");
    fgets(str, MAXN, stdin);
    scanf("%d", &key);
    char* cipher= cezar_cipher(str, key);
    printf("Text: %s\n", cipher);
    return EXIT_SUCCESS;

}
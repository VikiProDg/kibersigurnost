#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>
#define MAXN 1000
#define KEY_SIZE 8
int main()
{
    unsigned char key[KEY_SIZE] = "banichka";
    unsigned char input[MAXN];
    scanf("%s", input);
    unsigned int input_lenght = strlen(input);

    int padded_lenght = ( (input_lenght + 7) / 8) * 8;
    unsigned char padded_input[padded_lenght];
    unsigned char output[padded_lenght];
    memcpy(padded_input, input, input_lenght);
    memset(padded_input + input_lenght, padded_lenght - input_lenght, padded_lenght - input_lenght);


    DES_key_schedule key_schedule;
    DES_set_key((DES_cblock*) key, &key_schedule);
    for(int i=0; i < padded_lenght; i =+8)
    {
        DES_ecb_encrypt((DES_cblock*) (padded_input + i) ,(DES_cblock*) (output + i), &key_schedule, DES_ENCRYPT);


    }
    for(int i = 0; i < padded_lenght; i++)
    {
        printf("%02x" , output[i]);
    }

    return EXIT_SUCCESS;
    }

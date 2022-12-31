//Caesor Cipher using forward shift
#include<stdio.h>
#include<string.h>
#include "server.h"
int main(void)
{
    int status=1,choice,shift_key;
    while(status)
    {
        char plain_text[999]="",encrypted_text[999]="";
        display_menu();
        printf("Enter your choice:");
        scanf("%d",&choice);
        //Encryption:
        if(choice==1)
        {
                printf("\nEnter the key for encryption:");
                scanf("%d",&shift_key);
                strcpy(plain_text,read_text(plain_text));
                strcpy(encrypted_text,encrypt_message(plain_text,shift_key));
                printf("\nEncrypted text:\n");
                printf("%s\n\n",encrypted_text);
                dashed_line();
        }
        //Decrytion:
        else if(choice==2)
        {
                printf("\nEnter the key for decryption:");
                scanf("%d",&shift_key);
                strcpy(encrypted_text,read_text(encrypted_text));
                strcpy(plain_text,decrypt_message(encrypted_text,shift_key));
                printf("\nDecrypted text:\n");
                printf("%s\n\n",plain_text);
                dashed_line();
        }
        else if(choice==3)
        {
                status=0;
        }
        else
        {
            printf("Invalid choice!\nTry again.\n");
            dashed_line();
        }
        
    }
    return 0;
}
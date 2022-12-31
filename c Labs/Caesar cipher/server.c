#include<stdio.h>
#include<string.h>
#include "server.h"

//To display executable options available:
void display_menu(void)
{
    printf("Press...\n'1' to Encrypt message\n'2' to Decrypt message\n'3' to Quit\n\n");
}

/*
To Encrypt message using encrytion function E:
  1)For alphabets(case sensitive):E(x)=(x+n)%26
  2)For numbers                  :E(x)=(x+n)%10
  3)For special charactes        :E(x)=x
*/
char* encrypt_message(char *plain_text,int key)
{
	for(int text_index=0;text_index<strlen(plain_text);text_index++)
    {
        char ch=plain_text[text_index];
		if(ch>='a' && ch<='z')
        {
				plain_text[text_index]=(((ch-'a')+key)%26)+'a';
		}
		else if(ch>='A' && ch<='Z')
        {
				plain_text[text_index]=(((ch-'A')+key)%26)+'A';			
		}
        else if(ch>='0' && ch<='9')
        {
            plain_text[text_index]=(((ch-'0')+key)%10)+'0';
        }
		else
        {
			plain_text[text_index]=ch;
        }
    }
    return(plain_text);
}

/*
To Decrypt message using decrytion function D:
  1)For alphabets(case sensitive):D(x)=(x-n)%26
  2)For numbers                  :D(x)=(x-n)%10
  3)For special charactes        :D(x)=x
*/
char* decrypt_message(char *encrypted_text,int key)
{
	for(int text_index=0;text_index<strlen(encrypted_text);text_index++)
	{
		char ch=encrypted_text[text_index];
		if(ch>='a' && ch<='z')
		{
			encrypted_text[text_index]=(((ch-'z')-key)%26+'z');
		}
		else if(ch>='A' && ch<='Z')
		{
			encrypted_text[text_index]=(((ch-'Z')-key)%26+'Z');
		}
		else if (ch>='0' && ch<='9')
		{
			encrypted_text[text_index]=(((ch-'9')-key)%10+'9');
		}
		else
		{
			encrypted_text[text_index]=ch;
		}
	}
    return(encrypted_text);
}

//Function to read input text(paragraph/word/text) terminated by 'Tab' key on keyboard:
char* read_text(char *text)
{
    printf("\nEnter the text(paragraph/word/sentence) to be encrypted:\n[NOTE:Press 'Tab' key when paragraph/sentence/word ends and then press any key on your keyboard to continue]\n\n");
    scanf("%[^\t]s", text);
    return(text);
}

//To get a neat output:
void dashed_line(void)
{
	int some_random_length=100;
	for(int hyphen=0;hyphen<some_random_length;hyphen++)
	{
		printf("%c",'-');
	}
	printf("\n");
}
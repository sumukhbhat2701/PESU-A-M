#include <stdio.h>
#include <string.h>

/* remove all spaces and punctuation characters from the string */
void clean_str (char *str)
{
    char tmp_str [80];
    char *temp = tmp_str;
    char opt;
    char *ptr = str;

    while (*str != '\0')
    {
        switch ((opt = *str++))
        {
            case ' ': 
            case ',':
            case '.':
                break;
            default:
               *temp ++ = opt;
            break;
        }
    }
    *temp = '\0';
    strcpy (ptr, tmp_str);
}

int main (void)
{
    char *ptr;
    char inp_str [50];
    ptr = inp_str;

    printf ("Key in a string with spaces and other punctuation marks:");
    scanf ("%[^\n]", ptr);
    /* remove all spaces and punctuation characters from the string and display the modified string */
    clean_str (ptr);
    printf ("The modified string is %s\n", ptr);
    return 0;
}
    
#include<stdio.h>
#include<stdlib.h>  //With Key value pair
#include<string.h>

typedef struct trie
{
    int isleaf;
    char *value;
    struct trie *child[26];
}Trie;

Trie* get_node()
{
    Trie *temp = (Trie*)malloc(sizeof(Trie));
    temp->isleaf = 0;
    for(int i=0; i<26; i++)
        temp->child[i] = NULL;
    return temp;
}

void insert_pattern(Trie *root, char *pattern, char *val)
{
    Trie *curr = root;
    while(*pattern) // pattern[i] != '\0'
    {
        if(curr->child[*pattern - 'a'] == NULL)
            curr->child[*pattern - 'a'] = get_node();
        curr = curr->child[*pattern - 'a'];
        pattern++;
    }
    curr->isleaf = 1;
    curr->value = (char*)malloc(sizeof(char)*strlen(val));
    strcpy(curr->value, val);
}

int search(Trie *root, char *pattern, char* val)
{
    int flag = 0;
    Trie *curr = root;
    while(*pattern)
    {
        if(curr->child[*pattern - 'a'] == NULL)
        {
           flag = 1;
           break; 
        }
        
        curr = curr->child[*pattern - 'a'];
        pattern++;
    }

    if(flag || curr->isleaf == 0)
        return 0;
    strcpy(val, curr->value);
    return 1;
}

int mp_search(Trie *root, char *text, char res[10][20])
{
    Trie *curr;
    char temp[20]; char *g; int i = 0;
    while(*text)
    {
        curr = root;
        g = text;
        int k = 0;
        while(*g)
        {
            if(curr->child[*g - 'a'] == NULL) break;
            curr = curr->child[*g - 'a'];
            temp[k++] = *g;
            g++;
            if(curr->isleaf){ temp[k] = '\0';
            strcpy(res[i], temp); i++;}
        }
    text++;
    }
    return --i;
}

int main()
{
    Trie *root = get_node(); char temp[20];
    char res1[10][20];
    insert_pattern(root, "pan", "tava");
    insert_pattern(root, "paneer", "protein");
    insert_pattern(root, "pat", "good");
    insert_pattern(root, "test", "exam");
    insert_pattern(root, "banner", "poster");

    // if(search(root, "pat", temp))
    //     printf("\nFound %s\n", temp);
    // else
    //     printf("\nNot Found!\n");

    // if(search(root, "pa", temp))
    //     printf("\nFound %s\n", temp);
    // else
    //     printf("\nNot Found!\n");

    //  if(search(root, "pan", temp))
    //     printf("\nFound %s\n", temp);
    // else
    //     printf("\nNot Found!\n");

    //  if(search(root, "and", temp))
    //     printf("\nFound %s\n", temp);
    // else
    //     printf("\nNot Found!\n");

    int n = mp_search(root, "batterpaneerrecipe", res1);

    for(int i=0; i<=n; i++)
        printf("%s", res1[i]);

    return 0;
    
}

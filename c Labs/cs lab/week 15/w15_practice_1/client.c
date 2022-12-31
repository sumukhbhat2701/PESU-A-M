#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE * fp;
    FILE * fp1;
    char f1[100];
    char f[1000];
    char newline[1000];
    int line, count;
    printf("Enter f1 of source file: ");
    scanf("%s", f1);
    printf("Enter line number to replace: ");
    scanf("%d", &line);
    fflush(stdin);
    printf("Replace '%d' line with: ", line);
    fgets(newline, 1000, stdin);
    fp  = fopen(f1, "r");
    fp1 = fopen("replace.tmp", "w"); 
    if (fp == NULL || fp1 == NULL)
    {
        printf("\nError in opening file!\n");
        exit(0);
    }
    count = 0;
    while ((fgets(f, 1000, fp)) != NULL)
    {
        count++;
        if (count == line)
            fputs(newline, fp1);
        else
            fputs(f, fp1);
    }
    fclose(fp);
    fclose(fp1);
    remove(f1);
    rename("replace.tmp", f1);
    printf("\nSuccessfully replaced '%d' line with '%s'.", line, newline);
    return 0;
}
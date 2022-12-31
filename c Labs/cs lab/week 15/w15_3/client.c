#include<stdio.h>
int main()
{
    FILE *fp;
    char f[100];
    char ch;
    int n;
    printf("Enter the name of file:");
    scanf("%s",f);
    fp=fopen(f,"w");
    if(fp!=NULL)
    {
    printf("Enter the number of lines to be written on a file:");
    scanf("%d",&n);
    printf("Enter the lines:\n");
    for(int i=0;i<=n;i++)
    {
        while((ch=getchar())!='\n')
        {
            fputc(ch,fp);
        }
        if(ch=='\n')
            fputc(ch,fp);
    }
    fclose(fp);
    fp=fopen(f,"r");
    if(fp!=NULL)
    {
    printf("Contents of the file %s is:",f);
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    }}
    else
    {
        printf("Errors in opening files!!\n");
    }
    
    return 0;
}
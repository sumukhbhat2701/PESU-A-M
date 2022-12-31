#include<stdio.h>
int main()
{
    FILE *fp1,*fp2,*fp3,*fp4;
    char f1[100],f2[100],f3[100];
    char ch;
    printf("Enter the name of first file:");
    scanf("%s",f1);
    printf("Enter the name of second file:");
    scanf("%s",f2);
    fp1=fopen(f1,"r");
    fp2=fopen(f2,"r");
    printf("Enter the file name where the contents of %s and %s to be copied:",f1,f2);
    scanf("%s",f3);
    fp3=fopen(f3,"w");
    fp4=fopen(f3,"r");
    if(fp1!=NULL || fp2!=NULL || fp3!=NULL || fp4!=NULL)
    {
    while((ch=fgetc(fp1))!=EOF)
    {
        fputc(ch,fp3);
    }
    fputc('\n',fp3);
    while((ch=fgetc(fp2))!=EOF)
    {
        fputc(ch,fp3);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    printf("The merge of %s and %s into %s is successful!\nContents of %s is:\n",f1,f2,f3,f3);
    while((ch=fgetc(fp4))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp4);
    }
    else
    {
        printf("Errors in opening files!!\n");
    }
    
    return 0;
}
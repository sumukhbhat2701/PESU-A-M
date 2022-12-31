#include<stdio.h>
int compare(FILE *fp1,FILE *fp2)
{
    char ch1,ch2,status=0;
    while(((ch1=fgetc(fp1))!=EOF) &&((ch2=fgetc(fp2))!=EOF))
        {
            if(ch1!=ch2)
            {
                status=1;
                break;
            }
        }
    return status;
}
int main()
{
    FILE *fp1,*fp2;
    char f1[100],f2[100];
    char ch1,ch2;
    int fstatus;
    printf("Enter name of a file:");
    scanf("%s",f1);
    printf("Enter name of a file:");
    scanf("%s",f2);
    fp1=fopen(f1,"r");
    fp2=fopen(f2,"r");
    if(fp1==NULL || fp2==NULL)
    {
        printf("Error in opening files!\n");
    }
    else
    {
    fstatus=compare(fp1,fp2);
    
    if(fstatus==0)
    {
        printf("%s and %s have same contents\n",f1,f2);
    }
    else
    {
        printf("%s and %s have different contents\n",f1,f2);
    }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
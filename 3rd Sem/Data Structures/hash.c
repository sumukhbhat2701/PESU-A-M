#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
	char srn[20];
	char name[30];
	float cgpa;
}STUD;
int hf(char *srn)
{
	char temp[5];int k=0;
	for(int i=10;i<13;i++)
	{
		temp[k++]=srn[i];
	}
	temp[k]='\0';
	return (atoi(temp)%47);
}
int search(STUD ht[50],char *srn)
{
	int hkey=hf(srn);
	if(strcmp(ht[hkey].srn,"\0")==0)
		return -1;
	else
		return 1;
}
void main()
{
	char temp[25];
	int hkey;int wish;
	STUD ht[50];
	for(int i=0;i<50;i++)
		strcpy(ht[i].srn,"\0");
	do{
		printf("enter the srn");
		scanf("%s",temp);
		hkey=hf(temp);
		if(!strcmp(ht[hkey].srn,"\0"))
		{
			strcpy(ht[hkey].srn,temp);
			printf("enter the name of the student");
			scanf("%s",ht[hkey].name);
			printf("enter the cgpa");
			scanf("%f",&ht[hkey].cgpa);
		}
		else
		{
			//linear probing
			int j=(hkey+1)%47;
			while(j!=hkey && strcmp(ht[j].srn,"\0"))
			{
				j=(j+1)%47;
			}
			if(j==hkey)
				printf("not valid insertion");
			else
			{
					strcpy(ht[j].srn,temp);
					printf("enter the name of the student");
					scanf("%s",ht[j].name);
					printf("enter the cgpa");
					scanf("%f",&ht[j].cgpa);
			}
		}
		printf("do you wish to continue \n");
		scanf("%d",&wish);
	}while(wish);
	printf("enter the srn of the student" );
	scanf("%s",temp);
	if(search(ht,temp))
		printf("found");
	else
		printf("not found");

}

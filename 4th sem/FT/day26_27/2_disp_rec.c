#include <stdio.h>
#include <stdlib.h>

struct Person
{
	char name[20];
	int age;
};
typedef struct Person person_t;

int main()
{
	person_t x;
	int opt;
	FILE* fp;
	fp = fopen("person.dat", "r+");
	if(fp == NULL) { printf("error in opening file\n"); exit(1); }
	printf("read given record\n enter record # from 1 to 5 : ");
	scanf("%d", &opt);
	while(opt)
	{
		fseek(fp, (opt - 1) * sizeof(person_t), SEEK_SET);
		fread(&x, sizeof(person_t), 1, fp);
		printf("record read : %s %d\n", x.name, x.age);
		getchar();
		printf("read given record\n enter record # from 1 to 5 : ");
		scanf("%d", &opt);
	}
	
	fclose(fp);
}

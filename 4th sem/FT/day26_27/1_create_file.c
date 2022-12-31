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
	FILE* fp;
	fp = fopen("person.dat", "w");
	if(fp == NULL) { printf("error in opening file\n"); exit(1); }
	int n = 5;
	person_t x;
	while(n--)
	{
		scanf("%s %d", x.name, &x.age);
		fwrite(&x, sizeof(x), 1, fp);
	}
	fclose(fp);
}

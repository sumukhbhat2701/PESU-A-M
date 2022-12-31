#include<stdio.h>
#include<string.h>
#define MAX 500
int t[MAX];
void shifttable(char p[]) {
	int i,j,m;
	m=strlen(p);
	for (i=0;i<MAX;i++)
	  t[i]=m;
	for (j=0;j<m-1;j++)
	  t[p[j]]=m-1-j;
}
int horspool(char src[],char p[]) {
	int i,j,k,m,n; int comp=0,shifts=0;
	n=strlen(src);
	m=strlen(p);
	printf("\nLength of text=%d",n);
	printf("\n Length of pattern=%d",m);
	i=m-1;
	while(i<n) {
		k=0;
		while((k<m)&&(p[m-1-k]==src[i-k]))
		{  k++; comp++; }
        printf("K=%d\n",k);
        if(k<m)
            comp+=1;
		if(k==m)
		   {printf("#COMP=%d;#SHIFTS=%d\n",comp,shifts);return(i-m+1);} 
           
        else
		  { shifts+=t[src[i]]; i+=t[src[i]]; }
	}
    printf("#COMP=%d;#SHIFTS=%d\n",comp,shifts);
	return -1;
}
void main() {
	char src[100],p[100];
	int pos;
	printf("Enter the text in which pattern is to be searched:\n");
	scanf("%s",src);
	printf("Enter the pattern to be searched:\n");
	scanf("%s",p);
	shifttable(p);
	pos=horspool(src,p);
	if(pos>=0)
	  printf("\n The desired pattern was found starting from position %d",pos+1); else
	  printf("\n The pattern was not found in the given text\n");

}
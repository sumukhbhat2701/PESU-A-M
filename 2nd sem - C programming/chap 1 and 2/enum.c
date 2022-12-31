#include<stdio.h> 
  
enum year{Jan, Feb, Mar, Apr, May, Jun, Jul,  
          Aug, Sep, Oct, Nov, Dec}; 
  
int main() 
{ 
  int i; 
   for (i=Jan; i<=Dec; i++)       
      printf("%d ", i); 
        
   return 0;
}
 /*
#include<stdio.h> 
  
enum week{Mon, Tue=5, Wed, Thur, Fri, Sat, Sun}; 
  
int main() 
{ 
    enum week day; 
	enum week day1;
enum week day3;
    day = Wed; 
	day1=Tue;
	day3=Mon;
    printf("%d\n",day); 
printf("%d\n",day1);
printf("%d\n",day3); 
    return 0; 
}   
*/ 
#include<stdio.h>
struct s{
    struct s *n;
    int a;
};
typedef struct s S;
extern int x=10;
void foo(int x){
    printf("%d",x);
}
int main(){
    char c[100]={'b','c','d','e','f','g','h','a','b','c','d','e','f','a','b','c','d','e','f','a','b','c','d','e','f','a','b','c','d','e','f','a','b','c','d','e','f','a','b','c','d','e','f','a','b','c','d','e','f','a','b','c','d','e','f','a','b','c','d','e','f','a','b','c','d','e','f','a','a','b','c','d','e','f','a','b','c','d','e','f','a','b','c','d','e','f','a','b','c','d','e','f','a','b','c','d','e','f'};
    S* a = (void *)(c+4);
    a->n = NULL;
    a->a = 5;
    printf("%d\n",sizeof(S));
    for(int i=0;i<100;i++){
        printf("%c-%d\n",c[i],i);
    }
    // foo(5);
    // int x=10,y=5;
    // printf("%d",sizeof(unsigned long long));
    return 0;
}
#include <stdio.h>
typedef struct individual
{
    int age;
    int height;
    char name[20];
    char father[20];
    char mother[20];
} INDIVIDUAL;

void get_values (INDIVIDUAL *per)
{
    printf ("Key in the name:");
    scanf ("%s", per->name);
    printf ("Key in the age:");
    scanf ("%d", &per->age);
}

void display_values (INDIVIDUAL per)
{
    printf ("Name is %s\n", per.name);
    printf ("Age is %d\n", per.age);
}

int main (void)
{
    INDIVIDUAL per;
    get_values (&per);
    display_values (per);
    return 0;
}

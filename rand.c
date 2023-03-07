#include<stdio.h>

#include<time.h>


int main()
{
    int i;
    srand(time(NULL));
    for(i=0;i<10;i++)
    {
        printf("%d\n",(rand()%100)%37);
    }
    return 0;
}
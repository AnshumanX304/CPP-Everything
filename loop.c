#include<conio.h>
#include<stdio.h>
int main()
{   
    printf("enter the upper limit of the interval until which the even numbers are to be printed ::::");
    int n;
    scanf("%d",&n);
    int i=102;
    do
    {
        if(i%2==0)
            printf("%d \n",i);
        i++;
    }while (i<=n);
    
    
    return 0;

}
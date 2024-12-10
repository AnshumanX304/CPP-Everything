#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()

{
    int n;
    printf("Enter the value of N ::: \n");
    scanf("%d",&n);
    srand(time(0));
    int num;
    num=1+rand()%n;
    int sample;
    for(int i=0;i<10;i++)
    {
        printf("Guess the number between 1 and ");
        printf("%d",n);
        printf(" :::\n");
        scanf("%d",&sample);
        if(sample==num)
        {
            printf("You have guessed the correct number in ");
            printf("%d",i+1);
            printf(" attempts");
            break;

        }
        else if(sample<num)
            printf("Guess a higher number ! \n");
        else if(sample>num)
            printf("Guess a lower number ! \n");
        else
            printf("Invalid entry ! \n");
    }
    return 0;

}
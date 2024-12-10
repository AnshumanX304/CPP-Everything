#include<stdio.h>
#include<string.h>
void enter(char *stname,int *stmarks,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter the student name");
        gets(stname[i][24]);
        printf("Enter the marks");
        for(int j=0;j<4;j++)
        {
            scanf("%d",&stmarks[i][j]);
        }
    }

}
int main()
{
    printf("Enter the number of entries to be made ::");
    int n;
    scanf("%d",&n);
    char stname[n][24];
    int stmarks[n][4];
    
    enter(stname,stmarks,n);

    return 0;
}
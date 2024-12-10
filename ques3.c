#include<stdio.h>
#include<conio.h>
struct eligible
{
    int maths;
    int physics;
    int chem;

};
void selection(struct eligible s);
void enter(struct eligible s)
{
    printf("Enter the marks in mathematics :::\n");
    scanf("%d",&s.maths);
    printf("Enter the marks in physics :::\n");
    scanf("%d",&s.physics);
    printf("Enter the marks in chemistry :::\n");
    scanf("%d",&s.chem);
    selection(s);
}
void selection(struct eligible s)
{
    int total=s.maths+s.physics+s.chem;
    int mathphy=s.maths+s.physics;
    if(s.maths>=60 && s.physics>=50 && s.chem>=40 && (total>=200 ||mathphy>=150))
    {
        printf("The given student is eligible !\n\n");
    }
    else
    {
        printf("The given student is not eligible !\n\n");
    }
}
int main()
{
    struct eligible s;
    printf("Enter the number of students who are to be checked :::\n\n\n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the marks of student ");
        printf("%d",i+1);
        printf(" :::\n");
        enter(s);
    }
    return 0;


}
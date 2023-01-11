#include<stdio.h>
int main()
{
int i,j,n,num;
printf("enter the number of rows:");
scanf("%d",&n);
for(i=0;i<=n;i++)
{
num=1;
for(j=0;j<=i;j++)
{
if(j == 0||j == i)
{
printf("%4d",1);
}
else
{
num=num*(i-j+1)/j;
printf("%4d",num);
}
}
printf("\n");
}
return 0;
}

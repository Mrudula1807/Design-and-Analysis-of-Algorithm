#include <stdio.h>
int main()
{
int n1, n2, i, gcd;
printf("Enter first integer: ");
scanf("%d",&n1);
printf("\nEnter second integer: ");
scanf("%d",&n2);
for(i=1; i <= n1 && i <= n2; ++i)
{
if(n1%i==0 && n2%i==0)
gcd = i;
}
printf("G.C.D of %d and %d is %d", n1, n2, gcd);
return 0;
}

#include<stdio.h>
int main()
{
int Number, Remainder, Sum=0;
printf("\n Enter any number:");
scanf("%d", &Number);
while(Number > 0)
{
Remainder = Number % 10;
Sum = Sum+ Remainder;
Number = Number / 10;
}
printf("\n Sum of the digits of Given Number = %d", Sum);
return 0;
}


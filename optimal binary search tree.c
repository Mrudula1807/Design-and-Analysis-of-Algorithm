#include <stdio.h>
#include <limits.h>
int sum(int frequency[], int i, int j);
int optCost(int frequency[], int i, int j)
{
if (j < i)
return 0;
if (j == i)
return frequency[i];
int freqsum = sum(frequency, i, j);
int min = INT_MAX;
for (int r = i; r <= j; ++r)
{
int cost = optCost(frequency, i, r-1) +optCost(frequency, r+1, j);
if (cost < min)
min = cost;
}
return min + freqsum;
}
int Opt_SearchTree(int kys[], int frequency[], int n)
{
return optCost(frequency, 0, n-1);
}
int sum(int frequency[], int i, int j)
{
int s = 0;
for (int k = i; k <=j; k++)
s += frequency[k];
return s;
}
int main()
{
int kys[] = {10, 12, 20};
int frequency[] = {34, 8, 50};
int n = sizeof(kys)/sizeof(kys[0]);
printf("Cost of Optimal BST is %d ",Opt_SearchTree(kys, frequency, n));
return 0;
}

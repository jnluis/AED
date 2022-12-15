//
// Tomás Oliveira e Silva, AED, October 2021
//
// the functions for the extra exercises of class P.04
//

#include <stdio.h>
#include "elapsed_time.h"

int g1(int n)
{
  int i,j,r = 0;

  for(i = 0;i <= n;i++)
    for(j = i;j >= 0;j--)
      r += i - j;
  return r;
}

int g2(int n)
{
  int r = 0;

  for(int i = 0;i < 2 * n;i += 2)
    for(int j = i;j <= 2 * n;j += 2)
      r += j;
  return r;
}

void g3(int n,int *a)
{
  for(int i = 1;i <= n;i++)
    for(int j = i;j <= n;j += i)
      a[j] = i;
}

int g4(int n)
{
  int r = 0;

  for(int i = 1;i <= n;i *= 2)
    r += i;
  return r;
}

int main(void)
{
  double dt1,dt2,dt3,dt4;
  int r1,r2,r4;
  int n;
  //place your code 
  for(int p=1;p<=15;p+=1){
    n=1 <<p; // n = 2 levantado a p
    // n = p;
    int a[n];
    dt1 = cpu_time(); r1= g1(n); dt1= cpu_time()-dt1;printf("%4d 1 %10d %20.15f\n",n,r1,dt1);
    dt2 = cpu_time(); r2= g2(n); dt2= cpu_time()-dt2;printf("%4d 2 %10d %20.15f\n",n,r2,dt2);
    dt3 = cpu_time(); g3(n,a);  dt3= cpu_time()-dt3;printf("%4d 3 %30.15f\n",(int)n,dt3);
    dt4 = cpu_time(); r4= g4(n); dt4= cpu_time()-dt4;printf("%4d 4 %10d %20.15f\n",n,r4,dt4);
  }
}

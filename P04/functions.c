//
// Tomás Oliveira e Silva, AED, October 2021
//
// the functions for the first exercise of class P.04
// (for a given positive value of n, find a formula for the return value of each function)
//

#include <stdio.h>
#include "elapsed_time.h"

int f1(int n)
{
  int i,r=0;

  for(i = 1;i <= n;i++)
    r += 1;
  return r;
}

int f2(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= i;j++)
      r += 1;
  return r;
}

int f3(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= n;j++)
      r += 1;
  return r;
}

int f4(int n)
{
  int i,r=0;

  for(i = 1;i <= n;i++)
    r += i;
  return r;
}

int f5(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = i;j <= n;j++)
      r += 1;
  return r;
}

int f6(int n)
{
  int i,j,r=0;

  for(i = 1;i <= n;i++)
    for(j = 1;j <= i;j++)
      r += j;
  return r;
}

int main(void)
{
  int n,f;
  double t1,t2;
  for(int p=1; p<15;p++){
    
    n= 1 << p;
  }
  for (int n=0;n<1000;n++){
    t1= cpu_time();f= f1(n); t2= cpu_time(); printf("%.15f      ",t2 -t1);
    t1= cpu_time();f= f2(n); t2= cpu_time(); printf("%.15f      ",t2 -t1);
    t1= cpu_time();f= f3(n); t2= cpu_time(); printf("%.15f      ",t2 -t1);
    t1= cpu_time();f= f4(n); t2= cpu_time(); printf("%.15f      ",t2 -t1);
    t1= cpu_time();f= f5(n); t2= cpu_time(); printf("%.15f      ",t2 -t1);
    t1= cpu_time();f= f6(n); t2= cpu_time(); printf("%.15f      \n",t2 -t1);
  }
}

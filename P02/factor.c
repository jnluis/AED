//
// Tomás Oliveira e Silva, AED, October 2021
//
// buggy program to factor integers larger than 1
//

#include <stdio.h>
#include <stdlib.h>

int factor(int n,int *prime_factors,int *multiplicity)
{
  long int d,n_factors;

  n_factors = 0;
  //
  // try the factors d = 2,3,5,7,9,...
  //   these include all the primes, as well as many odd composite numbers
  //   these last are harmless, but slow the program down
  //   getting rid of them would, however, require much more complicated code
  //   the expression (d+1)|1 has the effect of adding 1 to d if d is even and adding 2 if it is odd
  //     note that the expression (x|1) is the bitwise or of the bits of x with the bits of the constant 1,
  //     so in this case it makes the least significant bit of the result always 1 (odd integer!)
  //
  //     d  d+1  (d+1)|1
  //    --  ---  -------
  //     2    3        3
  //     3    4        5
  //     4    5        5
  //     5    6        7
  //
  // the following code has a bug (possible arithmetic overflow); correct it!
  //
  for(d = 2;d * d <= n;d = (d + 1) | 1)
    if(n % d == 0)
    {
      prime_factors[n_factors] = d; // d is a prime factor
      multiplicity[n_factors] = 0;
      do
      {
        n /= d;
        multiplicity[n_factors]++;
      }
      while(n % d == 0);
      n_factors++;
    }
  if(n > 1)
  { // the remaining divisor, if any, must be a prime number
    prime_factors[n_factors] = n;
    multiplicity[n_factors++] = 1;
  }
  return n_factors;
}

int main(int argc,char **argv)
{
  int i,j,nf,f[16],m[16]; // the product of the first 16 primes is larger than 2^64
  long n;
  for(i = 1;i < argc;i++)
    if((n = atol(argv[i])) > 1)
    {
      nf = factor(n,f,m);
      printf("%ld = ",n);
      for(j = 0;j < nf;j++)
        if(m[j] == 1)
          printf("%s%d",(j == 0) ? "" : "*",f[j]);
        else
          printf("%s%d^%d",(j == 0) ? "" : "*",f[j],m[j]);
      printf(" (%s)\n",(nf == 1 && m[0] == 1) ? "prime" : "composite");
    }
	// ACHAR DIVISORES 
	int c[16];
  for (int i=0; i<16;i++)
    c[i]=0; // inicializar os valores do array com o valor 0
	int k=0;
	while (k<nf){
		int d = 1;
		for (int p=0;p<nf;p++){
		for (int x=0;x<c[p];x++){
			d = d * f[p];
	}
		}
		printf("Divisor : %d \n" , d);
		k = 0;
		while (k<nf){
		if (c[k] < m[k]){
			c[k]++;
			break;
		}
		else{
			c[k] = 0;
			k++;
		}
	}
	}
  return 0;
}

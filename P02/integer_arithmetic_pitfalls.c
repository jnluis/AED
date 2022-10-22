//
// Tomás Oliveira e Silva, AED, October 2021
//
// explain the program output
//
// try also compiling the program with the -Wsign-compare compilation flag
//

#include <stdio.h>

int main(void)
{
  unsigned int i = 1;
  int j = -1;
  int k = -2147483648; // o k mantem-se negativo porque em complemento para 2, este numero é o limite de valores represntáveis, sendo -2³²-¹

  printf("original i = %u\n",i);
  printf("original j = %d\n",j);
  printf("original k = %d\n",k);
  // compare i with j
  if(i > j) // estamos a comparar alhos com bugalhos! Uma variavel é com sinal, e a outra sem sinal
    printf("i > j is true\n");
  else
    printf("i > j is false\n");
  // replace k by its absolute value and print the result
  if(k < 0)
    k = -k;
  printf("absolute value of k = %d\n",k);
  return 0;
}

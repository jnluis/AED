//
// Tomás Oliveira e Silva, AED, October 2021
//
// list all command line arguments
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[argc]) {
  long int conv_int;
  char *ptr;
  for(int i = 0;i < argc;i++){
    //usar o atoi
    //conv_int = atoi(argv[i]); // usar o atoi não faz nenhum check ao input
    //printf("argv[%2d] = \"%d\"\n",i,conv_int); //As aspas que aparecem no output de nºs inteiros deve-se ao facto de nesta lista, estarem lá as aspas para qualquer tipo de valor
    conv_int = strtol (argv[i],&ptr,10);
    printf("argv[%2d] = \"%s \"\n",i,argv[i]);
    printf("%ld\n",conv_int);
  }  
  return 0;
}

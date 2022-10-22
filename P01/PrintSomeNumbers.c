#include <math.h>
#include <stdio.h>
void do_it(int N)
{
    int i;
    FILE *file;
    file = fopen("table2.txt","w"); 

    fprintf(file," n    sin(n)     cos(n)\n");
    fprintf(file,"--   -----       ---------\n");
    
    double conversion = M_PI/180;

    for(i = 1;i <= N;i++){
        fprintf(file,"%2d %10.5f %10.5f\n",i,sin(((double)i)*conversion) ,cos((double)i)*conversion);
    }
    fclose(file); 
}
    int main(void)
{
    do_it(90);
    return 0;
}
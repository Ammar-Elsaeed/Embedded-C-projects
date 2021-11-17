#include <stdio.h>
#include <stdlib.h>

/* Without using functions, you are required to write a code to calculate the exponential function using Taylor series.
 Your program is required to ask the use to enter the exponent and the number of iteration and then print the exponential result.*/
int main()
{
    printf("please enter the exponent and number of iterations \n");
    long int exponent =0;
    long int numiterations =0;
    scanf("%d", &exponent);
    scanf("%d",&numiterations);
    double num=1;
    double sum=1;
    double denum=1;
    for(int i=1;i<numiterations;i++){
        num = num*exponent;
        denum = i * denum;
        sum = sum + num/denum;
    }
    printf("sum: %f",sum);
    return 0;
}

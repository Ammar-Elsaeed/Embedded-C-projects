#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
    if ((i>=4-j)&&(i<=j+4)&&(i>=j-4)&&(i<=12-j)){
        printf("*");
    }
    else{
        printf(" ");
    }
    }
    printf("\n");
    }

     unsigned int number,numrotations;
     int direction;
    printf("the number: ");
    scanf("%u", &number);
    printf("number of rotations: ");
    scanf("%u", &numrotations);
    printf("rotation direction: ");
    scanf("%u", &direction);
    //unsigned char number2 = (unsigned char)number;
    int newnum=0;
    if(direction==0){
       newnum = (number>>numrotations) | (number<<(32-numrotations));
    }
    if(direction==1){
       newnum = (number<<numrotations) | (number>>(32-numrotations));
    }
    printf("%u",newnum);
    printf("\n");


int sum1=1;
int sum0=0;
int sum = 0;
int numseries;
scanf("%i",&numseries);
for(int x=0;x<numseries;x++)
    {if(x==0)
    printf("%d \n",0);
    else if(x==1)
    printf("%d \n",1);
    else{
     sum = sum0 + sum1 ;
     sum0 = sum1;
     sum1=sum;
     printf("%u",sum);
     printf("\n");}
}
return 0;
}

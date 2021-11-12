#include <stdio.h>
#include <stdlib.h>

int main()
{/*
    int num1;
    int num2;
    printf("Please enter the first number /n");
    scanf("%d", &num1);
    printf("Please enter the second number /n");
    scanf("%d", &num2);
    int sum = num1+num2;
    printf("%d",sum);
    // Tenary operator: bolean expression ? ____ : _____ */

//task-1:
    float u;
    float t;
    float a;
    printf("Please enter the velocity\n");
    scanf("%f", &u);
    printf("Please enter the time\n");
    scanf("%f", &t);
    printf("Please enter the acceleration\n");
    scanf("%f", &a);
    float v = u + a*t ;
    float s = u*t + 0.5 * a * t*t;
    printf("the velocity and distance respectively are: %f %f", v,s );


//task-2:

    float num1;
    float num2;
    float num3;
    printf("Please enter the first number\n");
    scanf("%f", &num1);
    printf("Please enter the second number\n");
    scanf("%f", &num2);
    printf("Please enter the third number\n");
    scanf("%f", &num3);
    float sum = num1+num2+num3;
    float product = num1*num2*num3;
    float average = sum/3 ;
    float min = num1<num2 ? num1:num2;
    min = min<num3 ? min:num3;
    float max = num1>num2 ? num1:num2;
    max = max>num3 ? max:num3;
    printf("%f",sum);
    printf("%f",product);
    printf("%f",average);
    printf("%f",min);
    printf("%f",max);

//task3:
    int secondsinput;
     printf("Please enter the total time in seconds\n");
     scanf("%i", &secondsinput);
     int seconds = secondsinput%60;
     int totalminutes = (secondsinput/60);
     int hours = totalminutes / 60;
     int actualminutes = totalminutes % 60 ;
     printf("%d %d %d",hours ,actualminutes,seconds);








}

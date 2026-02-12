#include <stdio.h>
int main (){
    int mark1, mark2;
    float average;

    printf ("Input the first mark: ");
    scanf ("%d", &mark1);

    printf ("Input the second mark: ");
    scanf ("%d", &mark2);

    average = (mark1+mark2)/2.0;
    printf ("The average is: %f\n", average);

    return 0;
}
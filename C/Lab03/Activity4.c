/*Write a C program to do the following.
a) Create an array called data to store the monthly average rainfall for a period of one
year.
b) Input the values from the keyboard and store them in the array.
c) Find the month with the maximum rainfall
d) Find the month with the minimum rainfall*/

#include <stdio.h>

int main(){
    float data [12];
    int maxMonth=0, minMonth=0;

    printf("Enter mothly average rainfall for a each month");
        for(int i=0;i<=12;i++){
            printf("Month %d: ", i);
            scanf("%f", &data[i]);
        }

        for(int i=1;i<12;i++){
            if(data[i] > data[maxMonth]){
                maxMonth = i;
            }

            if(data[i] < data[minMonth]){
                minMonth = i;
            }
        }


        printf("Maximum rainfall in month",data[maxMonth], maxMonth);
        printf("Minimum rainfall in month",data[minMonth], minMonth);

        return 0;
}
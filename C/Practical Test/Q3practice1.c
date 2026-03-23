#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int mid = n/2;

    int sum1 = 0,sum2 = 0;

    //first half
    for (int i = 0 ; i < mid ; i++){
        sum1 += arr[i];
    }

    //Second half
    for (int i = mid ; i < n ; i++){
        sum2 += arr[i];
    }

    int total = sum2 + sum1;
    float avg = float(total)/n ;

     printf("Sum 1 is %d\n", sum1);


    float avg = (float)sum / n;

    printf("Total = %d\n", sum);
    printf("Average = %.2f\n", avg);

    return 0;
}
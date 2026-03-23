#include <stdio.h>
#include <pthread.h>

#define MAX 100

int arr[MAX]; // shared array
int n, t;     // n = elements, t = threads

// Structure to pass data to each thread
typedef struct {
    int start; // start index
    int end;   // end index
    int sum;   // partial sum
} ThreadData;

// Thread function
void* compute_sum(void* arg) {
    // Convert argument to ThreadData
    ThreadData* data = (ThreadData*)arg;

    data->sum = 0;

    // Calculate sum for assigned range
    for (int i = data->start; i < data->end; i++) {
        data->sum += arr[i];
    }

    // Print thread work
    printf("Thread %lu processed [%d - %d]\n",
           pthread_self(), data->start, data->end - 1);

    return NULL;
}

int main() {
    // Get number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get number of threads
    printf("Enter number of threads: ");
    scanf("%d", &t);

    pthread_t threads[t];     // thread IDs
    ThreadData data[t];       // data for each thread

    // Divide work
    int base = n / t;         // equal part
    int extra = n % t;        // leftover
    int index = 0;

    // Create threads
    for (int i = 0; i < t; i++) {
        data[i].start = index;
        data[i].end = index + base + (i < extra ? 1 : 0);

        index = data[i].end;

        pthread_create(&threads[i], NULL, compute_sum, &data[i]);
    }

    int total = 0;

    // Wait for all threads and collect results
    for (int i = 0; i < t; i++) {
        pthread_join(threads[i], NULL);
        total += data[i].sum;
    }

    // Calculate average
    float avg = (float)total / n;

    printf("Total Sum = %d\n", total);
    printf("Average = %.2f\n", avg);

    return 0;
}

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Thread function
void* find_primes(void* arg) {
    // Get value of n from pointer
    int n = *(int*)arg;

    // Print IDs
    printf("Thread ID: %lu\n", pthread_self());
    printf("Process ID: %d\n", getpid());

    // Check each number from 2 to n
    for (int i = 2; i <= n; i++) {
        int isPrime = 1; // assume prime

        // Check divisibility
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = 0; // not prime
                break;
            }
        }

        // If prime, print it
        if (isPrime)
            printf("%d ", i);
    }

    printf("\n");
    return NULL;
}

int main() {
    int n;

    // Get input
    printf("Enter n: ");
    scanf("%d", &n);

    pthread_t tid; // thread ID

    // Create thread
    pthread_create(&tid, NULL, find_primes, &n);

    // Wait for thread to finish
    pthread_join(tid, NULL);

    printf("Main thread: Worker finished\n");

    return 0;
}

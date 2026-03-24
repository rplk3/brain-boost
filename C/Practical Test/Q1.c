#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n;

    // Get number of terms
    printf("Enter number of terms: ");
    scanf("%d", &n);

    // Create a new process
    pid_t pid = fork();

    if (pid == 0) {
        // This block runs in CHILD process

        // Print IDs
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        // Fibonacci logic
        int a = 0, b = 1, next;

        printf("Fibonacci: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a);   // print current number
            next = a + b;       // calculate next
            a = b;              // shift values
            b = next;
        }
        printf("\n");

    } else {
        // This block runs in PARENT process

        wait(NULL); // wait until child finishes

        printf("Parent: Child finished execution\n");
    }

    return 0;
}

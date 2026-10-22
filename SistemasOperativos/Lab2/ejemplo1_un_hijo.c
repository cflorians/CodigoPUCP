#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t ret;

    printf("Antes de fork: PID = %d\n", getpid());
    fflush(stdout);

    ret = fork();
    if (ret < 0) {
        perror("fork");
        return 1;
    }
    if (ret == 0) {
        printf("Hijo:  fork devolvió %d, PID = %d, PPID = %d\n",
               (int)ret, getpid(), getppid());
    } else {
        printf("Padre: fork devolvió %d, PID = %d, PPID = %d\n",
               (int)ret, getpid(), getppid());
    }
    return 0;
}

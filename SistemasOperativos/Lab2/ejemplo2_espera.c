#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t ret;
    int estado;

    ret = fork();
    if (ret < 0) {
        perror("fork");
        return 1;
    }
    if (ret == 0) {
        printf("Hijo PID = %d: trabajo breve y termino.\n", getpid());
        fflush(stdout);
        _exit(0);
    }

    printf("Padre PID = %d: espero al hijo %d.\n", getpid(), (int)ret);
    fflush(stdout);
    if (wait(&estado) == -1) {
        perror("wait");
        return 1;
    }
    printf("Padre: el hijo ya no está. wait devolvió y el estado está en %d.\n",
           estado);
    return 0;
}

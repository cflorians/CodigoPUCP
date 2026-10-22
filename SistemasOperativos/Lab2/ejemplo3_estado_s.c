#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t ret;

    ret = fork();
    if (ret < 0) {
        perror("fork");
        return 1;
    }
    if (ret == 0) {
        printf("Hijo PID = %d: me suspendo con pause().\n", getpid());
        fflush(stdout);
        pause();
        _exit(0);
    }

    printf("Padre PID = %d. En otra terminal ejecuta:\n", getpid());
    printf("  ps -o pid,ppid,stat,comm -p %d\n", (int)ret);
    printf("Luego vuelve y presiona Enter para enviar SIGTERM y hacer wait.\n");
    fflush(stdout);
    getchar();

    if (kill(ret, SIGTERM) == -1) {
        perror("kill");
        return 1;
    }
    if (wait(NULL) == -1) {
        perror("wait");
        return 1;
    }
    printf("Padre: recolecté al hijo %d.\n", (int)ret);
    return 0;
}

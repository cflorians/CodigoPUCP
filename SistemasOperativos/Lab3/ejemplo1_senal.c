#define _POSIX_C_SOURCE 200809L
/*
 * Ejemplo de la guía previa: una señal como medio de comunicación.
 * Compilar:
 *   gcc -std=c17 -Wall -Wextra -g ejemplo1_senal.c -o ejemplo1
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static volatile sig_atomic_t recibida = 0;

static void manejador(int signo)
{
    (void)signo;
    recibida = 1;
}

int main(void)
{
    struct sigaction sa;
    pid_t ret;

    sa.sa_handler = manejador;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("[Padre] PID = %d. Espero SIGUSR1.\n", getpid());
    fflush(stdout);

    ret = fork();
    if (ret < 0) {
        perror("fork");
        return 1;
    }
    if (ret == 0) {
        printf("[Hijo] envío SIGUSR1 a %d.\n", getppid());
        fflush(stdout);
        if (kill(getppid(), SIGUSR1) == -1) {
            perror("kill");
            _exit(1);
        }
        _exit(0);
    }

    while (recibida == 0)
        pause();

    printf("[Padre] señal recibida. recolecto al hijo.\n");
    if (wait(NULL) == -1) {
        perror("wait");
        return 1;
    }
    return 0;
}

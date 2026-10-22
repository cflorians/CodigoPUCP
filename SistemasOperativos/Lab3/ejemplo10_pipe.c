#define _POSIX_C_SOURCE 200809L
/*
 * Ejemplo de la guía previa: pipe anónimo.
 * Compilar:
 *   gcc -std=c17 -Wall -Wextra -g ejemplo10_pipe.c -o ejemplo10
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int fd[2];
    pid_t ret;
    char buf[64];
    ssize_t n;

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    ret = fork();
    if (ret < 0) {
        perror("fork");
        close(fd[0]);
        close(fd[1]);
        return 1;
    }
    if (ret == 0) {
        close(fd[0]);
        if (write(fd[1], "hola-pipe", 9) != 9) {
            perror("write");
            close(fd[1]);
            _exit(1);
        }
        close(fd[1]);
        _exit(0);
    }

    close(fd[1]);
    n = read(fd[0], buf, sizeof(buf) - 1);
    if (n < 0) {
        perror("read");
        close(fd[0]);
        wait(NULL);
        return 1;
    }
    buf[n] = '\0';
    printf("[Padre] leí %zd bytes: %s\n", n, buf);
    close(fd[0]);

    if (wait(NULL) == -1)
        perror("wait");
    return 0;
}

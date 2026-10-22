#define _POSIX_C_SOURCE 200809L
/*
 * Ejemplo de la guía previa: FIFO (pipe con nombre).
 * Compilar:
 *   gcc -std=c17 -Wall -Wextra -g ejemplo2_fifo.c -o ejemplo2
 */
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define RUTA_FIFO "/tmp/so_lab3_fifo"

int main(void)
{
    pid_t ret;
    int fd;
    char buf[64];
    ssize_t n;

    unlink(RUTA_FIFO);
    if (mkfifo(RUTA_FIFO, 0600) == -1) {
        perror("mkfifo");
        return 1;
    }

    ret = fork();
    if (ret < 0) {
        perror("fork");
        unlink(RUTA_FIFO);
        return 1;
    }
    if (ret == 0) {
        fd = open(RUTA_FIFO, O_WRONLY);
        if (fd == -1) {
            perror("open escritor");
            _exit(1);
        }
        if (write(fd, "hola-fifo", 9) != 9) {
            perror("write");
            close(fd);
            _exit(1);
        }
        close(fd);
        _exit(0);
    }

    fd = open(RUTA_FIFO, O_RDONLY);
    if (fd == -1) {
        perror("open lector");
        wait(NULL);
        unlink(RUTA_FIFO);
        return 1;
    }
    n = read(fd, buf, sizeof(buf) - 1);
    if (n < 0) {
        perror("read");
        close(fd);
        wait(NULL);
        unlink(RUTA_FIFO);
        return 1;
    }
    buf[n] = '\0';
    printf("[Padre] leí %zd bytes: %s\n", n, buf);
    close(fd);

    if (wait(NULL) == -1)
        perror("wait");
    unlink(RUTA_FIFO);
    return 0;
}

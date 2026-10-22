#define _POSIX_C_SOURCE 200809L
/*
 * Ejemplo de la guía previa: sleep() no sincroniza.
 * El hijo espera un segundo y lee. El padre escribe a los tres segundos.
 * El hijo no ve el valor nuevo: durmió, no esperó un evento.
 * Compilar:
 *   gcc -std=c17 -Wall -Wextra -g ejemplo6_sleep.c -o ejemplo6 -lrt
 */
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_NOMBRE "/so_lab3_ej6"

int main(void)
{
    int fd;
    int *valor;
    pid_t ret;

    shm_unlink(SHM_NOMBRE);

    fd = shm_open(SHM_NOMBRE, O_CREAT | O_RDWR, 0600);
    if (fd == -1) {
        perror("shm_open");
        return 1;
    }
    if (ftruncate(fd, sizeof(int)) == -1) {
        perror("ftruncate");
        close(fd);
        return 1;
    }
    valor = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                 MAP_SHARED, fd, 0);
    if (valor == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }
    close(fd);
    *valor = 0;

    ret = fork();
    if (ret < 0) {
        perror("fork");
        return 1;
    }
    if (ret == 0) {
        sleep(1);
        printf("[Hijo] después de sleep(1) leí %d (quería 42).\n", *valor);
        fflush(stdout);
        munmap(valor, sizeof(int));
        _exit(0);
    }

    sleep(3);
    *valor = 42;
    printf("[Padre] escribí 42 después de sleep(3).\n");
    if (wait(NULL) == -1)
        perror("wait");

    munmap(valor, sizeof(int));
    shm_unlink(SHM_NOMBRE);
    return 0;
}

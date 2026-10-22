#define _POSIX_C_SOURCE 200809L
/*
 * Ejemplo de la guía previa: memoria compartida POSIX (ciclo completo).
 * Compilar:
 *   gcc -std=c17 -Wall -Wextra -g ejemplo4_shm.c -o ejemplo4 -lrt
 */
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_NOMBRE "/so_lab3_ej4"

struct dato {
    int escrito_por_padre;
    int escrito_por_hijo;
};

int main(void)
{
    int fd;
    struct dato *d;
    pid_t ret;

    shm_unlink(SHM_NOMBRE);

    fd = shm_open(SHM_NOMBRE, O_CREAT | O_RDWR, 0600);
    if (fd == -1) {
        perror("shm_open");
        return 1;
    }
    if (ftruncate(fd, sizeof(struct dato)) == -1) {
        perror("ftruncate");
        close(fd);
        shm_unlink(SHM_NOMBRE);
        return 1;
    }
    d = mmap(NULL, sizeof(struct dato), PROT_READ | PROT_WRITE,
             MAP_SHARED, fd, 0);
    if (d == MAP_FAILED) {
        perror("mmap");
        close(fd);
        shm_unlink(SHM_NOMBRE);
        return 1;
    }
    close(fd);

    d->escrito_por_padre = 2026;
    d->escrito_por_hijo = 0;
    printf("[Padre] escribí %d. Mira /dev/shm%s\n",
           d->escrito_por_padre, SHM_NOMBRE);
    fflush(stdout);

    ret = fork();
    if (ret < 0) {
        perror("fork");
        munmap(d, sizeof(struct dato));
        shm_unlink(SHM_NOMBRE);
        return 1;
    }
    if (ret == 0) {
        printf("[Hijo] leí del padre %d. Escribo 17.\n",
               d->escrito_por_padre);
        fflush(stdout);
        d->escrito_por_hijo = 17;
        munmap(d, sizeof(struct dato));
        _exit(0);
    }

    if (wait(NULL) == -1)
        perror("wait");
    printf("[Padre] el hijo dejó %d.\n", d->escrito_por_hijo);

    munmap(d, sizeof(struct dato));
    shm_unlink(SHM_NOMBRE);
    return 0;
}

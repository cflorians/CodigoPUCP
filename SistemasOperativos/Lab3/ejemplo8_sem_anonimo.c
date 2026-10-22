#define _POSIX_C_SOURCE 200809L
/*
 * Ejemplo de la guía previa: semáforo POSIX sin nombre, en memoria compartida.
 * pshared = 1: el semáforo lo usan varios procesos.
 * Valor inicial 1: funciona como mutex alrededor de un contador pequeño.
 * Compilar:
 *   gcc -std=c17 -Wall -Wextra -g ejemplo8_sem_anonimo.c -o ejemplo8 -lrt -pthread
 */
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_NOMBRE "/so_lab3_ej8"
#define VUELTAS 5

struct shared {
    sem_t mutex;
    int total;
};

int main(void)
{
    int fd;
    struct shared *d;
    pid_t ret;
    int i;

    shm_unlink(SHM_NOMBRE);

    fd = shm_open(SHM_NOMBRE, O_CREAT | O_RDWR, 0600);
    if (fd == -1) {
        perror("shm_open");
        return 1;
    }
    if (ftruncate(fd, sizeof(struct shared)) == -1) {
        perror("ftruncate");
        close(fd);
        return 1;
    }
    d = mmap(NULL, sizeof(struct shared), PROT_READ | PROT_WRITE,
             MAP_SHARED, fd, 0);
    if (d == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }
    close(fd);

    d->total = 0;
    if (sem_init(&d->mutex, 1, 1) == -1) {
        perror("sem_init");
        munmap(d, sizeof(struct shared));
        shm_unlink(SHM_NOMBRE);
        return 1;
    }

    ret = fork();
    if (ret < 0) {
        perror("fork");
        return 1;
    }
    if (ret == 0) {
        for (i = 0; i < VUELTAS; i++) {
            if (sem_wait(&d->mutex) == -1) {
                perror("sem_wait");
                _exit(1);
            }
            d->total++;
            if (sem_post(&d->mutex) == -1) {
                perror("sem_post");
                _exit(1);
            }
        }
        munmap(d, sizeof(struct shared));
        _exit(0);
    }

    for (i = 0; i < VUELTAS; i++) {
        if (sem_wait(&d->mutex) == -1) {
            perror("sem_wait");
            break;
        }
        d->total++;
        if (sem_post(&d->mutex) == -1) {
            perror("sem_post");
            break;
        }
    }
    if (wait(NULL) == -1)
        perror("wait");

    printf("total = %d (esperado %d)\n", d->total, 2 * VUELTAS);

    sem_destroy(&d->mutex);
    munmap(d, sizeof(struct shared));
    shm_unlink(SHM_NOMBRE);
    return 0;
}

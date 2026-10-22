#define _POSIX_C_SOURCE 200809L
/*
 * Ejemplo de la guía previa: semáforo POSIX con nombre.
 * Valor inicial 0: el hijo se bloquea en sem_wait hasta que el padre hace post.
 * No uses sleep() para esta coordinación: el semáforo es el evento.
 * Compilar:
 *   gcc -std=c17 -Wall -Wextra -g ejemplo7_sem_nombre.c -o ejemplo7 -lrt -pthread
 */
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define SEM_NOMBRE "/so_lab3_sem"

int main(void)
{
    sem_t *sem;
    pid_t ret;

    sem_unlink(SEM_NOMBRE);
    sem = sem_open(SEM_NOMBRE, O_CREAT, 0600, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    ret = fork();
    if (ret < 0) {
        perror("fork");
        sem_close(sem);
        sem_unlink(SEM_NOMBRE);
        return 1;
    }
    if (ret == 0) {
        printf("[Hijo] espero el aviso del padre.\n");
        fflush(stdout);
        if (sem_wait(sem) == -1) {
            perror("sem_wait");
            sem_close(sem);
            _exit(1);
        }
        printf("[Hijo] recibí el aviso. Continúo.\n");
        fflush(stdout);
        sem_close(sem);
        _exit(0);
    }

    printf("[Padre] Enter para avisar al hijo.\n");
    fflush(stdout);
    getchar();
    if (sem_post(sem) == -1)
        perror("sem_post");

    if (wait(NULL) == -1)
        perror("wait");
    sem_close(sem);
    sem_unlink(SEM_NOMBRE);
    return 0;
}

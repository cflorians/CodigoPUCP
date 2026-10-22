#define _POSIX_C_SOURCE 200809L
/*
 * Ejemplo de la guía previa: condición de carrera sobre un contador compartido.
 * Compilar:
 *   gcc -std=c17 -Wall -Wextra -g ejemplo5_carrera.c -o ejemplo5 -lrt
 *
 * Ejecuta varias veces. El valor final suele ser menor que el esperado.
 */
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_NOMBRE "/so_lab3_ej5"
#define ITERACIONES 300000

int main(void)
{
    int fd;
    int *contador;
    pid_t ret;
    int i;
    int tmp;

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
    contador = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                    MAP_SHARED, fd, 0);
    if (contador == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }
    close(fd);
    *contador = 0;

    ret = fork();
    if (ret < 0) {
        perror("fork");
        return 1;
    }
    if (ret == 0) {
        for (i = 0; i < ITERACIONES; i++) {
            tmp = *contador;
            tmp = tmp + 1;
            *contador = tmp;
        }
        munmap(contador, sizeof(int));
        _exit(0);
    }

    for (i = 0; i < ITERACIONES; i++) {
        tmp = *contador;
        tmp = tmp + 1;
        *contador = tmp;
    }
    if (wait(NULL) == -1)
        perror("wait");

    printf("Valor final = %d\n", *contador);
    printf("Valor esperado = %d\n", 2 * ITERACIONES);

    munmap(contador, sizeof(int));
    shm_unlink(SHM_NOMBRE);
    return 0;
}

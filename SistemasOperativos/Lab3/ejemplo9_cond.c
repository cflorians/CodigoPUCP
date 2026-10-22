#define _POSIX_C_SOURCE 200809L
/*
 * Ejemplo de la guía previa: un hilo avisa a otro con variable de condición.
 * Compilar:
 *   gcc -std=c17 -Wall -Wextra -g -pthread ejemplo9_cond.c -o ejemplo9
 */
#include <pthread.h>
#include <stdio.h>

static int listo = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

static void *trabajador(void *arg)
{
    (void)arg;
    printf("[trabajador] preparo el dato.\n");

    pthread_mutex_lock(&mtx);
    listo = 1;
    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&mtx);
    return NULL;
}

int main(void)
{
    pthread_t tid;
    int rc;

    rc = pthread_create(&tid, NULL, trabajador, NULL);
    if (rc != 0) {
        fprintf(stderr, "pthread_create: %d\n", rc);
        return 1;
    }

    pthread_mutex_lock(&mtx);
    while (listo == 0)
        pthread_cond_wait(&cv, &mtx);
    pthread_mutex_unlock(&mtx);

    printf("[main] listo = %d. Puedo continuar.\n", listo);

    rc = pthread_join(tid, NULL);
    if (rc != 0) {
        fprintf(stderr, "pthread_join: %d\n", rc);
        return 1;
    }
    return 0;
}

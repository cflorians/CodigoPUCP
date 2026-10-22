#define _POSIX_C_SOURCE 200809L
/*
 * Ejemplo de la guía previa: cola de mensajes POSIX.
 * Compilar:
 *   gcc -std=c17 -Wall -Wextra -g ejemplo3_mq.c -o ejemplo3 -lrt
 */
#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define MQ_NOMBRE "/so_lab3_mq"

int main(void)
{
    struct mq_attr attr;
    mqd_t q;
    pid_t ret;
    char buf[64];
    unsigned prio = 0;
    ssize_t n;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 4;
    attr.mq_msgsize = 32;
    attr.mq_curmsgs = 0;

    mq_unlink(MQ_NOMBRE);
    q = mq_open(MQ_NOMBRE, O_CREAT | O_RDWR, 0600, &attr);
    if (q == (mqd_t)-1) {
        perror("mq_open");
        return 1;
    }

    ret = fork();
    if (ret < 0) {
        perror("fork");
        mq_close(q);
        mq_unlink(MQ_NOMBRE);
        return 1;
    }
    if (ret == 0) {
        const char *msg = "aviso";
        if (mq_send(q, msg, strlen(msg), 1) == -1) {
            perror("mq_send");
            mq_close(q);
            _exit(1);
        }
        mq_close(q);
        _exit(0);
    }

    n = mq_receive(q, buf, sizeof(buf), &prio);
    if (n < 0) {
        perror("mq_receive");
        wait(NULL);
        mq_close(q);
        mq_unlink(MQ_NOMBRE);
        return 1;
    }
    buf[n] = '\0';
    printf("[Padre] mensaje='%s'  prioridad=%u  bytes=%zd\n", buf, prio, n);

    if (wait(NULL) == -1)
        perror("wait");
    mq_close(q);
    mq_unlink(MQ_NOMBRE);
    return 0;
}

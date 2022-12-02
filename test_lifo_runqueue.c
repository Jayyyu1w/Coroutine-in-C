#include <stdio.h>
#include "src/coroutine_int.h"
#define MAX_SIZE 20

int main(void)
{
    struct task_struct task[MAX_SIZE];
    struct rq rq;
    struct task_struct *tmp;

    rq_init(&rq);
    for (int i = 0; i < MAX_SIZE; i++) {
        task[i].tfd = i;
        printf("enqueue %d, return %d\n", i, rq_enqueue(&rq, &task[i]));
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        tmp = rq_dequeue(&rq);
        if (tmp)
            printf("dequeue %d\n", tmp->tfd);
        else
            printf("dequeue failed\n");
    }

    return 0;
}

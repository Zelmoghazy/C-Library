#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// PTHREAD SCOPE PROCESS schedules threads using PCS scheduling.
// PTHREAD SCOPE SYSTEM schedules threads using SCS scheduling
/*
a Pthread scheduling API.
The program first determines the existing contention scope and
sets it to PTHREAD SCOPE SYSTEM.
It then creates five separate threads that will run using the SCS scheduling policy.
Note that on some systems, only certain contention scope values are allowed.
For example, Linux and macOS systems allow only PTHREAD SCOPE SYSTEM.
*/

#define NUM_THREADS 5
void *runner(void *param);
int main()
{
    int scope;
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;
    /*Get Default attributes*/
    pthread_attr_init(&attr);
    if (pthread_attr_getscope(&attr, &scope) != 0)
        fprintf(stderr, "Unable to get scheduling scope\n");
    else
    {
        if (scope == PTHREAD_SCOPE_PROCESS)
            printf("PTHREAD_SCOPE_PROCESS\n");
        else if (scope == PTHREAD_SCOPE_SYSTEM)
            printf("PTHREAD_SCOPE_SYSTEM\n");
        else
            fprintf(stderr, "Illegal scope value.\n");
    }
    /* set the scheduling algorithm to PCS or SCS */
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
    /* create the threads */
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_create(&tid[i], &attr, runner, NULL);
    /* now join on each thread */
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(tid[i], NULL);
    system("pause");
}
/* Each thread will begin control in this function */
void *runner(void *param)
{
    /* do some work ... */
    pthread_exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sched.h>
#include <unistd.h>
#include <pthread.h>
void *countA(){
    clock_t start_t, end_t;
   double total_t;
   start_t = clock();

    int i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){
        i++;
    }
    end_t=clock();
    total_t = (double)(end_t - start_t)/ CLOCKS_PER_SEC;
    printf("Thread RR policy: %f\n", total_t);
    return NULL;
}
void *countB(){
    clock_t start_t, end_t;
   double total_t;
   start_t = clock();

    int i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){
        i++;
    }
    end_t=clock();
     total_t = (double)(end_t - start_t)/ CLOCKS_PER_SEC;
    printf("Thread FIFO policy: %f\n", total_t);
    return NULL;
}
void *countC(){
    clock_t start_t, end_t;
   double total_t;
   start_t = clock();
    int i = 1;
    for(long int j = 0 ; j < pow(2,32) ; j++){
        i++;
    }
    end_t=clock();
    total_t = (double)(end_t - start_t)/ CLOCKS_PER_SEC;
    printf("Thread OTHER policy: %f\n", total_t);
    return NULL;
}
int main(){
struct sched_param schedparam1,schedparam2,schedparam3;
pthread_attr_t attr1,attr2,attr3;
pthread_t thread1,thread2,thread3;
schedparam1.sched_priority = 1;
schedparam2.sched_priority = 1;
schedparam3.sched_priority = 1;

pthread_attr_init(&attr1);
pthread_attr_setinheritsched(&attr1, PTHREAD_EXPLICIT_SCHED);
pthread_attr_setschedpolicy(&attr1, SCHED_RR);
pthread_attr_setschedparam(&attr1, &schedparam1);

pthread_attr_init(&attr2);
pthread_attr_setinheritsched(&attr2, PTHREAD_EXPLICIT_SCHED);
pthread_attr_setschedpolicy(&attr2, SCHED_FIFO);
pthread_attr_setschedparam(&attr2, &schedparam2);

pthread_attr_init(&attr3);
pthread_attr_setinheritsched(&attr3, PTHREAD_EXPLICIT_SCHED);
pthread_attr_setschedpolicy(&attr3, SCHED_OTHER);
pthread_attr_setschedparam(&attr3, &schedparam3);

pthread_create(&thread1, &attr1, countA, NULL);
pthread_create(&thread2, &attr2, countB, NULL);
pthread_create(&thread3, &attr3, countC, NULL);
pthread_join(thread1,NULL);
pthread_attr_destroy(&attr1);
pthread_join(thread2,NULL);
pthread_attr_destroy(&attr2);
pthread_join(thread3,NULL);
pthread_attr_destroy(&attr3);
}
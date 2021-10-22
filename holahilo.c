#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 10000
int saldo;

pthread_mutex_t lockSaldo = PTHREAD_MUTEX_INITIALIZER;

int *printHola(void *arg){ //Regresa un apuntador genérico
    int saldoLocal;
    pthread_mutex_lock(&lockSaldo);
    saldoLocal += 100;
    saldoLocal = saldo;
    saldo = saldoLocal;
    pthread_mutex_unlock(&lockSaldo);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];//Variable tipo hilo, guardar info de función credito (ID´s)
    saldo = 0;
    for (int i=0; i<NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, printHola, NULL);
    }
    for (int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("El valor del saldo es %d\n", saldo);

    pthread_exit(NULL);
}
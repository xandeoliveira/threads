#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
 
#define NUM_THREADS 10
 
char saudacao [3][11] = {
    "Bom dia!\n",
    "Oi.\n",
    "Tudo bem?\n"
};
 
char despedida [3][11] = {
    "Valeu.\n",
    "Tchau.\n",
    "Até mais.\n"
};
 
void *threadBody (void *id) {
    long tid = (long) id ;
 
    int pos = rand() % 3;
    printf ("t%02ld: %s", tid, saudacao[pos]) ;
    sleep (3) ;
 
    pos = rand() % 3;
    printf ("t%02ld: %s", tid, despedida[pos]) ;
 
    pthread_exit (NULL) ;
}
 
int main () {
 
    srand(time(NULL));
 
    pthread_t thread [NUM_THREADS] ;
    long i, status ;
 
    for (i=0; i<NUM_THREADS; i++)
    {
        printf ("Fuction Main: criando uma thread %02ld\n", i) ;
 
        status = pthread_create (&thread[i], NULL, threadBody, (void *) i) ;
 
        if (status)
        {
            perror ("pthread_create") ;
            exit (1) ;
        }
    }
 
    pthread_exit (NULL) ;
}
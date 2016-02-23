#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

void *malloc_sample(void *tid);
void *calloc_sample(void *tid);
void *realoc_sample(void *tid);

int main()
{
    pthread_t malloc, calloc, realloc;
    pthread_create(&malloc, NULL, malloc_sample, NULL);
    pthread_create(&calloc, NULL, calloc_sample, NULL);
    pthread_create(&realloc, NULL, realoc_sample, NULL);

    pthread_join(malloc, NULL);
    pthread_join(calloc, NULL);
    pthread_join(realloc, NULL);
    
    return (EXIT_SUCCESS);
}

void *malloc_sample(void *tid)
{
    time_t t = clock();

    char *ptr = malloc(1000 * sizeof (char));
    if (!ptr)
    {
        fprintf(stderr, "Can't allocate memory!");
        exit(1);
    }

    free(ptr);
    printf("malloc %lf\n", (double) ((double) clock() - t) / CLOCKS_PER_SEC);
    return NULL;
}

void *calloc_sample(void *tid)
{
    time_t t = clock();

    char *ptr = calloc(1000, sizeof (char));
    if (!ptr)
    {
        fprintf(stderr, "Can't allocate memory!");
        exit(1);
    }
    free(ptr);
    printf("calloc %lf\n", (double) ((double) clock() - t) / CLOCKS_PER_SEC);
    return NULL;
}

void *realoc_sample(void *tid)
{
    char *ptr = calloc(1000, sizeof (char));
    time_t t = clock();
    ptr = realloc(ptr, 2000 * sizeof (char));
    if (!ptr)
    {
        fprintf(stderr, "Can't allocate memory!");
        exit(1);
    }
    free(ptr);
    printf("realoc %lf\n", (double) ((double) clock() - t) / CLOCKS_PER_SEC);
    return NULL;
}
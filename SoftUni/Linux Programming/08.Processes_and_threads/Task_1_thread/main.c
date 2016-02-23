#include "City.h"
#include <pthread.h>

int main()
{
    // User input.
#if !DEBUG
    printf("Enter coordinates space separate.\n");
    int i;
    for (i = 0; i < COUNT; i++)
    {
        printf("C%d: ", i);
        check_input(&cityCenter[i].x, &cityCenter[i].y, &cityCenter[i].z);
    }
#endif

    clock_t begin, end;
    double time_spend;
    begin = clock();

    pthread_mutex_init(&lock_vars, NULL);

    int t;
    for (t = 0; t < NUM_THREADS; t++)
    {
        if (pthread_create(&threads[t], NULL, start_calculation, NULL))
        {
            fprintf(stderr, "Error create thread!\n");
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++)
    {
        if (pthread_join(threads[t], NULL))
        {
            fprintf(stderr, "Error join thread!\n");
            exit(-1);
        }
    }

    puts("info..........");
    printf("The length of the highway: %f\n", info.highwayLenght);
    printf("The average distance between 2 cities directly connected: %f\n",
           info.average);
    printf("The longest distance between 2 cities: C%d - C%d: %f\n",
           info.maxDistance.cityA, info.maxDistance.cityB, info.maxDistance.distance);
    printf("The shortest distance between 2 cities: C%d - C%d: %f\n",
           info.minDistance.cityA, info.minDistance.cityB, info.minDistance.distance);

    time_spend = (double) ((end = clock()) - begin) / CLOCKS_PER_SEC;
    printf("Execute time %lf seconds\n", time_spend);

    pthread_mutex_destroy(&lock_vars);

    return (EXIT_SUCCESS);
}
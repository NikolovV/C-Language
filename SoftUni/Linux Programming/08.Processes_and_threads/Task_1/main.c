#include "City.h"

int main()
{
#if !DEBUG   
    City cityCenter[COUNT];
    printf("Enter coordinates space separate.\n");
    int j;
    for (j = 0; j < COUNT; j++)
    {
        printf("C%d: ", j);
        check_intInput(&cityCenter[j].x, &cityCenter[j].y, &cityCenter[j].z);
    }
#endif
    
    /* Debug */
#if DEBUG   
    City cityCenter[COUNT] = {
        {1, 0, 4},
        {2, 1, 14},
        {2, 0, 3},
        {7, 11, 4},
        {6, 24, 18},
        {12, 18, 22},
        {2, 26, 22},
        {10, 10, 10},
        {6, 14, 19},
        {12, 21, 23}
    };
#endif

    Distance minDistance, maxDistance;
    minDistance.distance = 0;
    maxDistance.distance = 0;
    float highwayLenght = 0, average;

    clock_t begin, end;
    double time_spend;
    begin = clock();

    int i, k = 0;
    for (i = 0; i < COUNT - 1; i++)
    {
        for (k = i + 1; k < COUNT - 1; k++)
        {
            float road = distance_between_city(cityCenter[i], cityCenter[k]);

            if (i == 0 && (k - 1) == i)
            {
                minDistance.distance = road;
                maxDistance.distance = road;
            }
            if ((k - 1) == i)
            {
                highwayLenght += road;
            }
            if (road < minDistance.distance)
            {
                minDistance.cityA = i;
                minDistance.cityB = k;
                minDistance.distance = road;
            }
            else if (road > maxDistance.distance)
            {
                maxDistance.cityA = i;
                maxDistance.cityB = k;
                maxDistance.distance = road;
            }
        }
    }

    average = highwayLenght / COUNT;

    printf("Info.........\n");
    printf("The length of the highway: %f\n", highwayLenght);
    printf("The average distance between 2 cities directly connected: %f\n", average);
    printf("The longest distance between 2 cities: C%d - C%d: %f\n",
           maxDistance.cityA, maxDistance.cityB, maxDistance.distance);
    printf("The shortest distance between 2 cities: C%d - C%d: %f\n",
           minDistance.cityA, minDistance.cityB, minDistance.distance);

    time_spend = (double) ((end = clock()) - begin) / CLOCKS_PER_SEC;
    printf("Execute time %lf seconds\n", time_spend);

    return (EXIT_SUCCESS);
}

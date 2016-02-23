#include "City.h"

void *start_calculation(void *arg)
{
    pthread_mutex_lock(&lock_vars);

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

    info.highwayLenght = 0.0;
    int i, k = 0;
    for (i = 0; i < COUNT - 1; i++)
    {
        for (k = i + 1; k < COUNT - 1; k++)
        {
            float road = distance_between_city(cityCenter[i], cityCenter[k]);

            if (i == 0 && (k - 1) == i)
            {
                info.minDistance.distance = road;
                info.maxDistance.distance = road;
            }
            if ((k - 1) == i)
            {
                info.highwayLenght += road;
            }
            if (road < info.minDistance.distance)
            {
                info.minDistance.cityA = i;
                info.minDistance.cityB = k;
                info.minDistance.distance = road;
            }
            else if (road > info.maxDistance.distance)
            {
                info.maxDistance.cityA = i;
                info.maxDistance.cityB = k;
                info.maxDistance.distance = road;
            }
        }
    }

    info.average = info.highwayLenght / COUNT;
    pthread_mutex_unlock(&lock_vars);

    return NULL;
}
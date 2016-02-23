#include "City.h"

float distance_between_city(City A, City B)
{
    float disatance = sqrt((pow_custom((B.x - A.x), 2) +
                           pow_custom((B.y - A.y), 2) +
                           pow_custom((B.z - A.z), 2)));
    return disatance;
}

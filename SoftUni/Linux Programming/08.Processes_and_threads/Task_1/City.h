#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DEBUG 0

#define COUNT 10

typedef struct City {
    int x;
    int y;
    int z;
} City;

typedef struct Distance {
    int cityA;
    int cityB;
    float distance;
} Distance;

void check_intInput(int *x, int *y, int *z);
float pow_custom(float number, int base);
float distance_between_city(City A, City B);

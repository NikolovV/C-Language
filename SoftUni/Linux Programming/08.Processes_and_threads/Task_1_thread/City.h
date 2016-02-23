#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

#define DEBUG 0

#define COUNT 10
#define NUM_THREADS 2

pthread_mutex_t lock_vars;
pthread_t threads[NUM_THREADS];

typedef struct City {
    int x;
    int y;
    int z;
} City;

City cityCenter[COUNT];

typedef struct Distance {
    int cityA;
    int cityB;
    float distance;
} Distance;

typedef struct InfoCity {
    Distance minDistance;
    Distance maxDistance;
    float highwayLenght, average;
} InfoCity;

InfoCity info;

void check_input(int *x, int *y, int *z);
float pow_custom(float number, int base);
float distance_between_city(City A, City B);
void *start_calculation(void *arg);

#ifndef CATEGORIZENUMBERSANDFINDMINMAXAVERAGE_H
#define	CATEGORIZENUMBERSANDFINDMINMAXAVERAGE_H

#define FLOATING_COMPARSION 0.0001

void check_intInput(int *a);
void fill_array(float str[], int size);
bool is_floating_point(float a);
int colect_floating(const float *str, int size, float a[]);
int colect_round(const float *str, int size, float destiantion[]);
float get_mininal(const float str[], int size);
float get_maxinal(const float str[], int size);
float get_sum(const float str[], int size);
float get_average(const float str[], int size);
void print_info(const float str[], int size);

#endif	/* CATEGORIZENUMBERSANDFINDMINMAXAVERAGE_H */


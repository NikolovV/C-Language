#pragma once
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

int pow_integers(int number, int base);
unsigned long sqrt_integers(unsigned long number);
int triangle_perimeter(int a, int b, int c);
unsigned int vector_lenght(int X1, int Y1, int X2, int Y2);
unsigned int triangle_surface(int perimeter, int a, int b, int c);
int tringle_height(int area, int b);

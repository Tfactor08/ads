#ifndef ARRAY_UTIL_H
#define ARRAY_UTIL_H

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

void fill_array(int[], int);
void free_arrays(int**, int);
int** duplicate_arrays(int**, int, int*);
void print_array(int[], int);
void repeat_element(int, int[], int);
void break_into_sorted_subarrs(int, int[], int);
void swap_with_random(int, int[], int);

#endif

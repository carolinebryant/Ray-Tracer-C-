/* 
CPSC 102 
Project 4 Basic Ray Tracer in C++
Name: Caroline Bryant
*/

#ifndef RAY_H
#define RAY_H

#include <math.h>
#include "vector.h"	

// ray type structure
typedef struct {

        VECTOR org;
        VECTOR dir;
} RAY_T;

// color type structure
typedef struct {

	double r;
	double g;
	double b;
} COLOR_T;

COLOR_T lighting (VECTOR light, VECTOR intersect_pt, VECTOR normal, COLOR_T obj_color, RAY_T ray);

#endif

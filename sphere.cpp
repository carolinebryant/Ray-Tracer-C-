/* 
CPSC 102 
Project 4 Basic Ray Tracer in C++
Name: Caroline Bryant
*/

#include <math.h>
#include "vector.h"
#include "ray.h"
#include "sphere.h"

using namespace std;

bool SPHERE :: intersect_sph (RAY_T ray, VECTOR &intersect_pt, VECTOR &normal) {

	double a, b, c;
	double t;
	

	// calculates a, b, and c to be used in quadratic formula
	a = 1;

	b = ray.dir.access(ray.org, this->ctr);
	
	c = ray.org.access(this->ctr, this->r);

	double t0 = 0, t1 = 0;

	// checking if the discriminant is negative
	if (((b*b) - (4*a*c)) < 0) {

		return false;
	}

	// computes quadratic formulas
	else { 
		t0 = ((-b - sqrt((b*b) - (4*a*c))) / 2*a);
		t1 = ((-b + sqrt((b*b) - (4*a*c))) / 2*a);	
	}

	// checking which t-value to use for the intersection point 
	if (t0 < 0 && t1 < 0) {
		return false;
	}

	else if (t1 > 0 && t0 < 0) {

		t = t1;
	}

	else if (t1 < 0 && t0 > 0) {

		t = t0;
	}

	else if (t1 < t0) {
		
		t = t1;
	}

	else if (t0 < t1) {

		t = t0;
	}

	// computing intersect point
	intersect_pt = ray.org + (ray.dir * t);

	// computing the normal line
	normal = (intersect_pt - this->ctr) / this->r; 

	return true;

}




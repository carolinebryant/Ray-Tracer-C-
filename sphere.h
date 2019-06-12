/* 
CPSC 102 
Project 4 Basic Ray Tracer in C++
Name: Caroline Bryant
*/

#ifndef SPHERE_H
#define SPHERE_H

using namespace std;

class SPHERE{

	VECTOR ctr;
	double r;
	COLOR_T color;

public:

	SPHERE () {};

	SPHERE (VECTOR ctr, double r) {

		this-> ctr = ctr;
		this-> r = r;
	}

	bool intersect_sph (RAY_T ray, VECTOR &intersect_pt, VECTOR &normal);
};

#endif
